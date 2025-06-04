#include "minishell.h"

int	ft_init_shell_envp(t_shell_data *shell_data, char **envp)
{
	if (!shell_data || !envp)
		return (EXIT_FAILURE);
	shell_data->envp = ft_duplicate_string_array(envp);
	if (!shell_data->envp)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_init_env_paths(t_shell_data *shell_state)
{
	if (!shell_state || !shell_state->envp)
		return (EXIT_FAILURE);
	shell_state->paths = ft_split_env_paths(shell_state->envp);
	if (!shell_state->paths)
		return (EXIT_FAILURE);
	if (ft_append_slash_to_paths(shell_state->paths) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
