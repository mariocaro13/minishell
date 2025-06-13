#ifndef EXPANDER_H
# define EXPANDER_H

char	**ft_expand_command_args(t_shell_data *shell_data, char **str);
char	*ft_expand_str(t_shell_data *shell_data, char *str);
void	ft_expander_caller(t_shell_data *shell_data,
			t_command_list **command_list);

// Dollar Sign
char	*ft_detect_dollar_sign(t_shell_data *shell_data, char *str);
size_t	ft_get_dollar_sign_index(const char *str);
int		ft_get_after_dollar_len(char *str, int start);

// Question mark
int		ft_process_question_mark(t_shell_data *shell_data, char **result);

// Utils
int		ft_process_env(t_shell_data *shell_data,
			char *str, int index, char **result);
bool	ft_should_process_env(char *str, int index);
void	ft_append_regular_char(const char *str, int *index, char **result);

#endif
