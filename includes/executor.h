#ifndef EXECUTOR_H
# define EXECUTOR_H

// check_redirections
int				check_redirections(t_commands_list *cmd);

// executor
int				ft_execute_commands(t_shell_data *shell_data);
int				executor(t_shell_data *shell_data);
int				pipe_wait(int *pid, int amount);

// handle_cmd
int				find_cmd(t_commands_list *cmd, t_shell_data *shell_data);
void			handle_cmd(t_commands_list *cmd, t_shell_data *shell_data);
void			dup_cmd(t_commands_list *cmd, t_shell_data *shell_data,
					int end[2], int fd_in);
void			ft_handle_command(t_commands_list *cmd, t_shell_data *shell_data);

// heredoc
int				send_heredoc(t_shell_data *shell_data, t_commands_list *cmd);
int				check_fd_heredoc(t_shell_data *shell_data, int end[2], t_commands_list *cmd);

#endif
