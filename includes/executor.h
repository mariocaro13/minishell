#ifndef EXECUTOR_H
# define EXECUTOR_H

// check_redirections
int		ft_handle_redirections(t_commands_list *cmd);
int		ft_check_append_outfile(t_lexer_list *redirections);
int		ft_handle_infile(char *file_name);
int		ft_handle_outfile(t_lexer_list *redirection);

// executor
int		ft_execute_commands(t_shell_data *shell_data);
int		ft_execute_pipeline_command(t_shell_data *shell_data);
int		ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount);

// ft_execute_command
int		ft_find_command(t_commands_list *cmd, t_shell_data *shell_data);
int		ft_execute_command(t_commands_list *cmd, t_shell_data *shell_data);
void	ft_dup_command(t_commands_list *cmd, t_shell_data *shell_data,
			int end[2], int fd_in);
void	ft_handle_command(t_commands_list *cmd,
			t_shell_data *shell_data);

// heredoc
int		ft_handle_heredoc(t_shell_data *shell_data, t_commands_list *cmd);
int		ft_get_fd_heredoc(t_shell_data *shell_data, int end[2],
			t_commands_list *cmd);
char	*ft_create_heredoc_filename(void);
int		ft_get_fd_heredoc(t_shell_data *shell_data, int end[2],
			t_commands_list *cmd);

#endif
