#ifndef UTILS_H
# define UTILS_H

// utils
bool	ft_is_whitespace(char c);
bool	ft_is_operator_char(char c);
bool	ft_is_special_token(const t_token token);
int		ft_skip_spaces(char *str, int index);
char	**ft_duplicate_string_array(char **arr);

// quote_utils
int		ft_get_matching_quote_index(const char *line, int start, char quote);
bool	ft_are_quotes_closed(const char *line);
int		ft_get_quote_len(int index, char *str, char del);
size_t	ft_count_quotes(char *str);
char	*ft_del_quotes(char *str, char c);
char	*ft_del_quotes_value(char *str);
char	*ft_apply_del_quotes(char *str, char quote_symbol);

// input_utils
char	*ft_get_trimmed_line(t_shell_data *shell_data);
char	*ft_build_prompt(t_shell_data *shell_data);

// str_utils
char	*ft_join_split_str(char **split_str, char *new_str);
char	**ft_resplit_str(char **double_arr);
char	*ft_char_to_str(char c);
char	*ft_strjoin_free(char *s1, char *s2);

// path_utils
int		ft_append_slash_if_missing(char **path);
int		ft_append_slash_to_paths(char **paths);

// env_utils
int		ft_strip_env_prefix(char **dest, char *env_entry, size_t prefix_len);
char	*ft_get_env_path(char **envp);
char	**ft_split_env_paths(char **envp);
int		ft_update_dir_from_env(t_shell_data *shell_data,
			const char *prefix, size_t prefix_len, char **dest);

// pipes_utils
void	ft_remove_leading_pipe(t_shell_data *shell_data);
int		ft_count_pipes_in_lexer(t_lexer_list *lexer_list);

// clean
void	ft_clean_shell_resources(t_shell_data *shell_data);
void	ft_clean_str(char **str);

#endif
