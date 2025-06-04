#include "minishell.h"

char	*join_split_str(char **split_str, char *new_str);
char	**resplit_str(char **double_arr);

int	find_cmd(t_commands_list *cmd, t_shell_data *shell_data)
{
	int		index;
	char	*mycmd;

	index = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, shell_data->envp);
	while (shell_data->paths[index])
	{
		mycmd = ft_strjoin(shell_data->paths[index], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, shell_data->envp);
		free(mycmd);
		index++;
	}
	return (ft_error_print_command_not_found(cmd->str[0]));
}

void	handle_cmd(t_commands_list *cmd, t_shell_data *shell_data)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(shell_data, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, shell_data);
	exit(exit_code);
}

void	dup_cmd(t_commands_list *cmd, t_shell_data *shell_data, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error_handle_msg(ERR_PIPE, shell_data);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error_handle_msg(ERR_PIPE, shell_data);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, shell_data);
}


