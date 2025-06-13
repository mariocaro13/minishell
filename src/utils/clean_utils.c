#include "minishell.h"

void	ft_clean_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_clean_shell_resources(t_shell_data *shell_data)
{
	if (!shell_data)
		return ;
	if (shell_data->envp)
	{
		ft_free_array(shell_data->envp);
		shell_data->envp = NULL;
	}
	if (shell_data->paths)
	{
		ft_free_array(shell_data->paths);
		shell_data->paths = NULL;
	}
}

void	ft_free_shell_data(t_shell_data *shell_data)
{
	if (!shell_data)
		return ;
	ft_free_array(shell_data->paths);
	ft_free_array(shell_data->envp);
	ft_clean_str(&shell_data->args);
	ft_clean_str(&shell_data->pwd);
	ft_clean_str(&shell_data->old_pwd);
	ft_clean_str(&shell_data->history_path);
	if (shell_data->command_list)
		ft_command_list_clear(&shell_data->command_list);
	if (shell_data->lexer_list)
	{
		ft_lexer_clear(&shell_data->lexer_list);
		free(shell_data->lexer_list);
	}
	if (shell_data->pid)
		free(shell_data->pid);
}
