/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:41 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_shell_dirs(t_shell_data *shell_data)
{
	int	index;

	if (!shell_data || !shell_data->envp)
		return (EXIT_FAILURE);
	index = 0;
	while (shell_data->envp[index])
	{
		if (!ft_strncmp(shell_data->envp[index],
				PWD_PREFIX, PWD_PREFIX_LEN))
			if (ft_strip_env_prefix(&shell_data->pwd,
					shell_data->envp[index], PWD_PREFIX_LEN))
				return (EXIT_FAILURE);
		if (!ft_strncmp(shell_data->envp[index],
				OLDPWD_PREFIX, OLDPWD_PREFIX_LEN))
		{
			if (ft_strip_env_prefix(&shell_data->old_pwd,
					shell_data->envp[index], OLDPWD_PREFIX_LEN))
			{
				free(shell_data->pwd);
				return (EXIT_FAILURE);
			}
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

void	ft_init_shell_data(t_shell_data *shell_data)
{
	shell_data->command_list = NULL;
	shell_data->lexer_list = NULL;
	shell_data->pipes = 0;
	shell_data->pid = NULL;
	shell_data->heredoc = false;
	free(shell_data->old_pwd);
	shell_data->old_pwd = NULL;
	shell_data->reset = false;
}

void	ft_init_global_shell_state(t_shell_data *shell_data)
{
	shell_data->state.should_stop_heredoc = false;
	shell_data->state.is_in_cmd = false;
	g_is_in_heredoc = false;
}

void	ft_init_signals(void)
{
	rl_event_hook = ft_rl_event_hook;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	ft_init_shell(t_shell_data *shell_data, char **envp)
{
	if (!shell_data || !envp)
		return (EXIT_FAILURE);
	shell_data->old_pwd = NULL;
	ft_init_shell_data(shell_data);
	if (ft_init_shell_envp(shell_data, envp) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (ft_init_shell_dirs(shell_data) != EXIT_SUCCESS)
	{
		ft_clean_shell_resources(shell_data);
		return (EXIT_FAILURE);
	}
	if (ft_init_env_paths(shell_data) != EXIT_SUCCESS)
	{
		ft_clean_shell_resources(shell_data);
		return (EXIT_FAILURE);
	}
	shell_data->state.error_num = 0;
	ft_init_global_shell_state(shell_data);
	ft_init_signals();
	return (EXIT_SUCCESS);
}
