#ifndef EXPANDER_H
# define EXPANDER_H

/**
 * @file expander.h
 * @brief Function declarations for variable and quote expansion in minishell.
 *
 * Provides functions for expanding environment variables, handling the dollar
 * sign, processing the special $? variable, and removing quotes from command
 * arguments.
 */

/**
*  ____        _ _              ____  _             
* |  _ \  ___ | | | __ _ _ __  / ___|(_) __ _ _ __  
* | | | |/ _ \| | |/ _` | '__| \___ \| |/ _` | '_ \ 
* | |_| | (_) | | | (_| | |     ___) | | (_| | | | |
* |____/ \___/|_|_|\__,_|_|    |____/|_|\__, |_| |_|
*                                       |___/       
*/

/**
 * @brief Expands all dollar sign variables in a string.
 *
 * Handles $VAR, $?, and other shell variable expansions.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str String to process.
 * @return Newly allocated string with variables expanded.
 */
char	*ft_detect_dollar_sign(t_shell_data *shell_data, char *str);

/**
 * @brief Gets the index after the first dollar sign in a string.
 *
 * @param str The string to search.
 * @return Index after the first '$', or 0 if not found.
 */
size_t	ft_get_dollar_sign_index(const char *str);

/**
 * @brief Gets the length of the variable name after a dollar sign.
 *
 * Used to determine how many characters to consider for variable expansion.
 *
 * @param str The string to search.
 * @param start Index of the dollar sign.
 * @return Index after the variable name.
 */
int		ft_get_after_dollar_len(char *str, int start);

/**
 * @brief Processes an environment variable expansion in a string.
 *
 * Searches for the variable in the environment and appends its value to result.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str The string to process.
 * @param index Index of the dollar sign.
 * @param result Pointer to the result string to update.
 * @return Number of characters processed for the variable.
 */
int		ft_process_env(t_shell_data *shell_data,
			char *str, int index, char **result);

/**
 * @brief Checks if the environment variable after a dollar sign should be
 * processed.
 *
 * Ensures the next character is not a space, quote, or end of string.
 *
 * @param str The string to check.
 * @param index Index of the dollar sign.
 * @return true if the variable should be processed, false otherwise.
 */
bool	ft_should_process_env(char *str, int index);

/**
 * @brief Appends a regular (non-variable) character to the result string.
 *
 * Used during variable expansion to copy non-variable characters.
 *
 * @param str The source string.
 * @param index Pointer to the current index in the source string.
 * @param result Pointer to the result string to update.
 */
void	ft_append_regular_char(const char *str, int *index, char **result);

/**
*  _____                            _             ____  _        _             
* | ____|_  ___ __   __ _ _ __   __| | ___ _ __  / ___|| |_ _ __(_)_ __   __ _ 
* |  _| \ \/ / '_ \ / _` | '_ \ / _` |/ _ \ '__| \___ \| __| '__| | '_ \ / _` |
* | |___ >  <| |_) | (_| | | | | (_| |  __/ |     ___) | |_| |  | | | | | (_| |
* |_____/_/\_\ .__/ \__,_|_| |_|\__,_|\___|_|    |____/ \__|_|  |_|_| |_|\__, |
*            |_|                                                         |___/ 
*/

/**
 * @brief Expands environment variables and removes quotes in a single string.
 *
 * Expands variables (e.g., $VAR, $?) and removes quotes from the string.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str String to expand and clean (will be freed).
 * @return Newly allocated expanded and cleaned string.
 */
char	*ft_expand_str(t_shell_data *shell_data, char *str);

/**
*  _____                            _           
* | ____|_  ___ __   __ _ _ __   __| | ___ _ __ 
* |  _| \ \/ / '_ \ / _` | '_ \ / _` |/ _ \ '__|
* | |___ >  <| |_) | (_| | | | | (_| |  __/ |   
* |_____/_/\_\ .__/ \__,_|_| |_|\__,_|\___|_|   
*            |_|                                
*/

/**
 * @brief Expands environment variables and removes quotes in a command argument
 * array.
 *
 * Iterates through each argument, expands variables (e.g., $VAR), and removes
 * quotes unless the command is 'export'.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str Array of command argument strings.
 * @return Newly allocated array with expanded and cleaned arguments.
 */
char	**ft_expand_command_args(t_shell_data *shell_data, char **str);

/**
 * @brief Calls the expander on the command list's arguments and redirections.
 *
 * Expands variables and removes quotes in both the command arguments and
 * redirection file names.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list to expand.
 */
void	ft_expander_caller(t_shell_data *shell_data,
			t_command_list **command_list);

/**
*   ___                  _   _               __  __            _    
*  / _ \ _   _  ___  ___| |_(_) ___  _ __   |  \/  | __ _ _ __| | __
* | | | | | | |/ _ \/ __| __| |/ _ \| '_ \  | |\/| |/ _` | '__| |/ /
* | |_| | |_| |  __/\__ \ |_| | (_) | | | | | |  | | (_| | |  |   < 
*  \__\_\\__,_|\___||___/\__|_|\___/|_| |_| |_|  |_|\__,_|_|  |_|\_\
*/

/**
 * @brief Expands the special variable $? to the last command's exit status.
 *
 * Frees the previous result and sets it to the string representation of the
 * exit code.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param result Pointer to the string to update.
 * @return Number of characters processed (always 2 for $?).
 */
int		ft_process_question_mark(t_shell_data *shell_data, char **result);

#endif
