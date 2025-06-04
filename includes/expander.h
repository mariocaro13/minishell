#ifndef EXPANDER_H
# define EXPANDER_H

char	**ft_expand_command_args(t_shell_data *shell_data, char **str);
char	*expander_str(t_shell_data *shell_data, char *str);
void	ft_expander_caller(t_shell_data *shell_data,
			t_commands_list **command_list);

// Dollar Sign
char	*detect_dollar_sign(t_shell_data *shell_data, char *str);
size_t	ft_find_dollar_sign(const char *str);

#endif
