#ifndef BUILTINS_H
# define BUILTINS_H

/**
 *  ____        _ _ _   _           
 * | __ ) _   _(_) | |_(_)_ __  ___ 
 * |  _ \| | | | | | __| | '_ \/ __|
 * | |_) | |_| | | | |_| | | | \__ \
 * |____/ \__,_|_|_|\__|_|_| |_|___/
 */

/**
 * @brief Returns a pointer to the builtin function matching the given string.
 *
 * This function:
 *   - Compares the input string with known builtin command names.
 *   - Returns a function pointer to the corresponding builtin implementation.
 *   - Returns NULL if the command is not a builtin.
 *
 * @param str Command name to check.
 * @return Function pointer to the builtin, or NULL if not found.
 */
int	(*ft_get_builtin_function(char *str))(t_shell_data *shell_data,
		t_command_list *command_list);

/**
 * @brief Updates the shell's PWD and OLDPWD variables after a directory change.
 *
 * This function:
 *   - Sets OLDPWD to the previous PWD.
 *   - Updates PWD to the current working directory.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_change_path(t_shell_data *shell_data);

/**
 * @brief Returns the index after the first '=' character in a string.
 *
 * @param str The string to search.
 * @return Index after the first '=', or 0 if not found.
 */
size_t	ft_get_equal_sign_index(char *str);

/**
 * @brief Removes quotes from a string value.
 *
 * This function:
 *   - Removes double or single quotes from the input string.
 *   - Returns a newly allocated string without quotes.
 *
 * @param str The string to process (will be freed).
 * @return New string without quotes.
 */
char	*ft_del_quotes_value(char *str);

/**
 * @brief Checks if a character is invalid for an identifier.
 *
 * This function:
 *   - Returns true if the character is a shell special symbol or not
 * allowed in identifiers.
 *
 * @param c Character to check.
 * @return 1 if invalid, 0 if valid.
 */
int		ft_check_valid_identifier(char c);

/**
 *  _____ _      ____    _ 
 * |  ___| |_   / ___|__| |
 * | |_  | __| | |   / _` |
 * |  _| | |_  | |__| (_| |
 * |_|    \__|  \____\__,_|
 */

/**
 * @brief Changes the current working directory.
 *
 * This function:
 *   - Changes the directory to the path specified in the command.
 *   - Updates shell PWD and OLDPWD.
 *   - Handles errors for invalid arguments or inaccessible directories.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_cd(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     _____     _           
 * |  ___| |_  | ____|___| |__   ___  
 * | |_  | __| |  _| / __| '_ \ / _ \ 
 * |  _| | |_  | |__| (__| | | | (_) |
 * |_|    \__| |_____\___|_| |_|\___/ 
 */

/**
 * @brief Prints arguments to standard output.
 *
 * This function:
 *   - Prints its arguments separated by spaces.
 *   - Supports the -n option to suppress the trailing newline.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS.
 */
int		ft_echo(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     ____              _ 
 * |  ___| |_  |  _ \__      ____| |
 * | |_  | __| | |_) \ \ /\ / / _` |
 * |  _| | |_  |  __/ \ V  V / (_| |
 * |_|    \__| |_|     \_/\_/ \__,_|
 */

/**
 * @brief Prints the current working directory.
 *
 * This function:
 *   - Outputs the value of PWD to standard output.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if PWD is not set.
 */
int		ft_pwd(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     _____            
 * |  ___| |_  | ____|_ ____   __
 * | |_  | __| |  _| | '_ \ \ / /
 * |  _| | |_  | |___| | | \ V / 
 * |_|    \__| |_____|_| |_|\_/  
 */

/**
 * @brief Prints the environment variables.
 *
 * This function:
 *   - Outputs all environment variables to standard output.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_env(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     _____      _ _   
 * |  ___| |_  | ____|_  _(_) |_ 
 * | |_  | __| |  _| \ \/ / | __|
 * |  _| | |_  | |___ >  <| | |_ 
 * |_|    \__| |_____/_/\_\_|\__|
 */

/**
 * @brief Exits the shell.
 *
 * This function:
 *   - Exits the shell with the specified exit code.
 *   - Handles numeric argument parsing and error messages.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS (does not return if exit is successful).
 */
int		ft_exit(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     _____                       _   
 * |  ___| |_  | ____|_  ___ __   ___  _ __| |_ 
 * | |_  | __| |  _| \ \/ / '_ \ / _ \| '__| __|
 * |  _| | |_  | |___ >  <| |_) | (_) | |  | |_ 
 * |_|    \__| |_____/_/\_\ .__/ \___/|_|   \__|
 *                        |_|                   
 */

/**
 * @brief Adds or updates environment variables.
 *
 * This function:
 *   - Adds new variables or updates existing ones in the environment.
 *   - Handles invalid identifiers and prints errors.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS.
 */
int		ft_export(t_shell_data *shell_data, t_command_list *command_list);

/**
 *  _____ _     _   _                _   
 * |  ___| |_  | | | |_ __  ___  ___| |_ 
 * | |_  | __| | | | | '_ \/ __|/ _ \ __|
 * |  _| | |_  | |_| | | | \__ \  __/ |_ 
 * |_|    \__|  \___/|_| |_|___/\___|\__|
 */

/**
 * @brief Removes environment variables.
 *
 * This function:
 *   - Removes the specified variable from the environment.
 *   - Handles invalid identifiers and prints errors.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_unset(t_shell_data *shell_data, t_command_list *command_list);

#endif
