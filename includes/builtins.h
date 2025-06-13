#ifndef BUILTINS_H
# define BUILTINS_H

//builtins
void	ft_change_path(t_shell_data *shell_data);

int		ft_echo(t_shell_data *shell_data, t_command_list *simple_cmd);

int		ft_pwd(t_shell_data *shell_data, t_command_list *simple_cmd);

int		ft_export(t_shell_data *shell_data, t_command_list *simple_cmd);

int		ft_unset(t_shell_data *shell_data, t_command_list *simple_cmd);

int		ft_env(t_shell_data *shell_data, t_command_list *simple_cmd);

int		ft_exit(t_shell_data *shell_data, t_command_list *simple_cmd);

int		mini_continue(t_shell_data *shell_data, t_command_list *simple_cmd);

size_t	ft_get_equal_sign_index(char *str);
int		ft_check_valid_identifier(char c);

int		(*ft_get_builtin_function(char *str))(t_shell_data *shell_data,
			t_command_list *simple_cmd);

// cd
int		ft_cd(t_shell_data *shell_data, t_command_list *simple_cmd);
char	*ft_get_path_ret(const char *env_var, t_shell_data *shell_data);
int		ft_get_specific_path(t_shell_data *shell_data, char *env_var);
void	ft_add_path_to_env(t_shell_data *shell_data);

#endif
