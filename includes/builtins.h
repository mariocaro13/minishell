#ifndef BUILTINS_H
# define BUILTINS_H

//builtins
void	change_path(t_shell_data *shell_data);

int		mini_echo(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_cd(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		mini_pwd(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_export(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_unset(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		mini_env(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		ft_exit(t_shell_data *shell_data, t_commands_list *simple_cmd);

int		mini_continue(t_shell_data *shell_data, t_commands_list *simple_cmd);

size_t	ft_equal_sign(char *str);
int		check_valid_identifier(char c);

#endif
