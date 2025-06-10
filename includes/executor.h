#ifndef EXECUTOR_H
# define EXECUTOR_H

// check_redirections
int		check_redirections(t_commands_list *cmd);

// executor
int		ft_execute_commands(t_shell_data *shell_data);
int		ft_execute_pipeline_command(t_shell_data *shell_data);
int		ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount);

// handle_cmd
int		find_cmd(t_commands_list *cmd, t_shell_data *shell_data);
void	handle_cmd(t_commands_list *cmd, t_shell_data *shell_data);
void	dup_cmd(t_commands_list *cmd, t_shell_data *shell_data,
			int end[2], int fd_in);
void	ft_handle_command(t_commands_list *cmd,
					t_shell_data *shell_data);

// heredoc
int		ft_send_heredoc(t_shell_data *shell_data, t_commands_list *cmd);
int		check_fd_heredoc(t_shell_data *shell_data, int end[2],
			t_commands_list *cmd);
char	*ft_create_heredoc_filename(void);
int		check_fd_heredoc(t_shell_data *shell_data, int end[2], t_commands_list *cmd);

#endif
