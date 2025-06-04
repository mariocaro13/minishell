#ifndef ERROR_H
# define ERROR_H

// clean
void	ft_clean_shell_resources(t_shell_data *shell_data);

// error handling
void	ft_error_parser(int error, t_shell_data *shell_data,
			t_lexer_list *lexer_list);
int		ft_error_parser_token(t_shell_data *shell_data,
			t_lexer_list *lexer_list, t_token token);
int		ft_error_pipe_handler(t_shell_data *shell_data, t_token token);

// Error MSG
void	ft_error_print_msg_token(t_token token);
int		ft_error_handle_msg(int error, t_shell_data *shell_data);
int		ft_error_print_command_not_found(char *str);
int		ft_error_print_export(char *c);

#endif
