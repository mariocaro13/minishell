/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:41 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:42 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/**
 * @file utils.h
 * @brief Utility function declarations for string, array, quote, 
 * environment, pipe, and cleanup operations in minishell.
 *
 * This header provides helpers for string manipulation, 
 * quote handling, environment variable management, pipe counting,
 * memory cleanup, and prompt building.
 */

/**
 *   ____                           _   _   _ _   _ _     
 *  / ___| ___ _ __   ___ _ __ __ _| | | | | | |_(_) |___ 
 * | |  _ / _ \ '_ \ / _ \ '__/ _` | | | | | | __| | / __|
 * | |_| |  __/ | | |  __/ | | (_| | | | |_| | |_| | \__ \
 *  \____|\___|_| |_|\___|_|  \__,_|_|  \___/ \__|_|_|___/
 */

/**
 * @brief Checks if a character is whitespace (space or tab).
 *
 * @param c Character to check.
 * @return true if whitespace, false otherwise.
 */
bool	ft_is_whitespace(char c);

/**
 * @brief Checks if a character is a shell operator (|, <, >).
 *
 * @param c Character to check.
 * @return true if operator, false otherwise.
 */
bool	ft_is_operator_char(char c);

/**
 * @brief Checks if a token is a special shell token (pipe or redirection).
 *
 * @param token Token to check.
 * @return true if special token, false otherwise.
 */
bool	ft_is_special_token(const t_token token);

/**
 * @brief Skips whitespace characters in a string starting from index.
 *
 * @param str Input string.
 * @param index Start index.
 * @return Number of whitespace characters skipped.
 */
int		ft_skip_spaces(char *str, int index);

/**
 * @brief Duplicates a NULL-terminated array of strings.
 *
 * @param arr Array of strings to duplicate.
 * @return Newly allocated duplicate array, or NULL on allocation failure.
 */
char	**ft_duplicate_string_array(char **arr);

/**
 *   ___              _         _   _ _   _ _     
 *  / _ \ _   _  ___ | |_ ___  | | | | |_(_) |___ 
 * | | | | | | |/ _ \| __/ _ \ | | | | __| | / __|
 * | |_| | |_| | (_) | ||  __/ | |_| | |_| | \__ \
 *  \__\_\\__,_|\___/ \__\___|  \___/ \__|_|_|___/
 */

/**
 * @brief Gets the index of the matching closing quote in a string.
 *
 * @param line Input string.
 * @param start Index of the opening quote.
 * @param quote Quote character to match.
 * @return Index of the matching quote, or -1 if not found.
 */
int		ft_get_matching_quote_index(const char *line, int start, char quote);

/**
 * @brief Checks if all quotes in a string are properly closed.
 *
 * @param line Input string.
 * @return true if all quotes are closed, false otherwise.
 */
bool	ft_are_quotes_closed(const char *line);

/**
 * @brief Gets the length of a quoted substring, including the quotes.
 *
 * @param index Start index of the quote.
 * @param str Input string.
 * @param del Quote character.
 * @return Length of the quoted substring, or -2 if not closed.
 */
int		ft_get_quote_len(int index, char *str, char del);

/**
 * @brief Counts the number of quotes in a string.
 *
 * @param str Input string.
 * @return Number of quote characters.
 */
size_t	ft_count_quotes(char *str);

/**
 * @brief Removes all occurrences of a quote character from a string.
 *
 * @param str String to process (will be freed).
 * @param c Quote character to remove.
 * @return New string without the quote character.
 */
char	*ft_del_quotes(char *str, char c);

/**
 * @brief Removes quotes from a string, freeing the original if changed.
 *
 * @param str String to process.
 * @param quote_symbol Quote character to remove.
 * @return New string without quotes.
 */
char	*ft_apply_del_quotes(char *str, char quote_symbol);

/**
 *  ___                   _     _   _ _   _ _     
 * |_ _|_ __  _ __  _   _| |_  | | | | |_(_) |___ 
 *  | || '_ \| '_ \| | | | __| | | | | __| | / __|
 *  | || | | | |_) | |_| | |_  | |_| | |_| | \__ \
 * |___|_| |_| .__/ \__,_|\__|  \___/ \__|_|_|___/
 *           |_|                                  
 */

/**
 * @brief Reads a line from the user, trims whitespace, and returns it.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return Newly allocated trimmed input line, or NULL on EOF or error.
 */
char	*ft_get_trimmed_line(t_shell_data *shell_data);

/**
 * @brief Builds the shell prompt string based on the current working directory.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return Newly allocated prompt string, or NULL on error.
 */
char	*ft_build_prompt(t_shell_data *shell_data);

/**
 *  ____  _        _               _   _ _   _ _     
 * / ___|| |_ _ __(_)_ __   __ _  | | | | |_(_) |___ 
 * \___ \| __| '__| | '_ \ / _` | | | | | __| | / __|
 *  ___) | |_| |  | | | | | (_| | | |_| | |_| | \__ \
 * |____/ \__|_|  |_|_| |_|\__, |  \___/ \__|_|_|___/
 *                         |___/                     
 */

/**
 * @brief Joins an array of strings into a single space-separated string.
 *
 * @param split_str Array of strings to join.
 * @param new_str (Unused, can be NULL).
 * @return Newly allocated joined string.
 */
char	*ft_join_split_str(char **split_str, char *new_str);

/**
 * @brief Resplits a double array of strings into a normalized array.
 *
 * Joins the array into a string and splits it again by spaces.
 *
 * @param double_arr Array of strings to resplit.
 * @return Newly allocated normalized array.
 */
char	**ft_resplit_str(char **double_arr);

/**
 * @brief Converts a character to a newly allocated string.
 *
 * @param c Character to convert.
 * @return Newly allocated string containing the character.
 */
char	*ft_char_to_str(char c);

/**
 * @brief Joins two strings and frees the first one.
 *
 * @param s1 First string (will be freed).
 * @param s2 Second string.
 * @return Newly allocated joined string.
 */
char	*ft_strjoin_free(char *s1, char *s2);

/**
 *  ____       _   _       _   _ _   _ _     
 * |  _ \ __ _| |_| |__   | | | | |_(_) |___ 
 * | |_) / _` | __| '_ \  | | | | __| | / __|
 * |  __/ (_| | |_| | | | | |_| | |_| | \__ \
 * |_|   \__,_|\__|_| |_|  \___/ \__|_|_|___/
 */

/**
 * @brief Appends a slash to a path string if missing.
 *
 * @param path Pointer to the path string (will be updated).
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on allocation error.
 */
int		ft_append_slash_if_missing(char **path);

/**
 * @brief Appends a slash to each path in an array if missing.
 *
 * @param paths Array of path strings.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on allocation error.
 */
int		ft_append_slash_to_paths(char **paths);

/**
 *  _____            _                                      _   
 * | ____|_ ____   _(_)_ __ ___  _ __  _ __ ___   ___ _ __ | |_ 
 * |  _| | '_ \ \ / / | '__/ _ \| '_ \| '_ ` _ \ / _ \ '_ \| __|
 * | |___| | | \ V /| | | | (_) | | | | | | | | |  __/ | | | |_ 
 * |_____|_| |_|\_/ |_|_|  \___/|_| |_|_| |_| |_|\___|_| |_|\__|
 * | | | | |_(_) |___                                           
 * | | | | __| | / __|                                          
 * | |_| | |_| | \__ \                                          
 *  \___/ \__|_|_|___/                                          
 */

/**
 * @brief Strips the prefix from an environment variable entry.
 *
 * Copies the value after the prefix into dest.
 *
 * @param dest Destination pointer for the value.
 * @param env_entry Environment variable entry string.
 * @param prefix_len Length of the prefix to strip.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_strip_env_prefix(char **dest, char *env_entry, size_t prefix_len);

/**
 * @brief Gets the PATH variable value from the environment.
 *
 * @param envp Array of environment variable strings.
 * @return Newly allocated PATH value, or NULL if not found.
 */
char	*ft_get_env_path(char **envp);

/**
 * @brief Splits the PATH variable into an array of directories.
 *
 * @param envp Array of environment variable strings.
 * @return Newly allocated array of path strings, or NULL on error.
 */
char	**ft_split_env_paths(char **envp);

/**
 * @brief Counts the number of environment variables in the array.
 *
 * @param envp Array of environment variable strings.
 * @return Number of entries in envp.
 */
size_t	ft_count_envp(char **envp);

/**
 *  ____  _              _   _ _   _ _     
 * |  _ \(_)_ __   ___  | | | | |_(_) |___ 
 * | |_) | | '_ \ / _ \ | | | | __| | / __|
 * |  __/| | |_) |  __/ | |_| | |_| | \__ \
 * |_|   |_| .__/ \___|  \___/ \__|_|_|___/
 *         |_|                             
 */

/**
 * @brief Removes a leading pipe token from the lexer list if present.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_remove_leading_pipe(t_shell_data *shell_data);

/**
 * @brief Counts the number of pipe tokens in the lexer list.
 *
 * @param lexer_list Pointer to the lexer list.
 * @return Number of pipe tokens.
 */
int		ft_count_pipes_in_lexer(t_lexer_list *lexer_list);

/**
 *   ____ _                                _   _ _   _ _     
 *  / ___| | ___  __ _ _ __  _   _ _ __   | | | | |_(_) |___ 
 * | |   | |/ _ \/ _` | '_ \| | | | '_ \  | | | | __| | / __|
 * | |___| |  __/ (_| | | | | |_| | |_) | | |_| | |_| | \__ \
 *  \____|_|\___|\__,_|_| |_|\__,_| .__/   \___/ \__|_|_|___/
 *                                |_|                        
 */

/**
 * @brief Frees the environment and path arrays in the shell data structure.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_clean_shell_resources(t_shell_data *shell_data);

/**
 * @brief Frees a string and sets its pointer to NULL.
 *
 * @param str Pointer to the string pointer to free.
 */
void	ft_clean_str(char **str);

/**
 * @brief Frees all dynamically allocated memory in the shell data structure.
 *
 * Frees paths, envp, args, pwd, old_pwd, history_path, command list, lexer list,
 * and pid array.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_free_shell_data(t_shell_data *shell_data);

#endif
