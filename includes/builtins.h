#ifndef BUILTINS_H
# define BUILTINS_H

//builtins
void	change_path(t_shell_data *shell_data);

int		ft_echo(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_cd(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_pwd(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_export(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_unset(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_env(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_exit(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		mini_continue(t_shell_data *shell_data, t_commands_list *simple_cmd);

size_t	ft_get_equal_sign_index(char *str);
int		ft_check_valid_identifier(char c);

int		(*ft_get_builtin_function(char *str))(t_shell_data *shell_data,
			t_commands_list *simple_cmd);

#endif
