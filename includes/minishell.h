#ifndef MINISHELL_H
# define MINISHELL_H

/**
* .----------------------------------------.
* | ___            _           _           |
* ||_ _|_ __   ___| |_   _  __| | ___  ___ |
* | | || '_ \ / __| | | | |/ _` |/ _ \/ __||
* | | || | | | (__| | |_| | (_| |  __/\__ \|
* ||___|_| |_|\___|_|\__,_|\__,_|\___||___/|
* '----------------------------------------'
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include "libft.h"
# include "colors.h"
# include "messages.h"
# include "defines.h"
# include "data.h"
# include "utils.h"
# include "init.h"
# include "signals.h"
# include "reset.h"
# include "error.h"
# include "parser.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"
# include "expander.h"

/**
*  ____  _          _ _   _                   
* / ___|| |__   ___| | | | | ___   ___  _ __  
* \___ \| '_ \ / _ \ | | | |/ _ \ / _ \| '_ \ 
*  ___) | | | |  __/ | | | | (_) | (_) | |_) |
* |____/|_| |_|\___|_|_| |_|\___/ \___/| .__/ 
*                                      |_|    
*/

/**
 * @brief Main shell loop. Handles reading user input, parsing,
 * executing commands, and managing shell state in a continuous
 * loop until exit.
 *
 * This function:
 * 	- Reads and trims a line from the user.
 *	- Adds the input to the shell history.
 *	- Validates the input (checks for closed quotes, builds token list).
 * 	- Parses the lexer list into commands.
 * 	- Executes the parsed commands.
 * 	- Resets the shell loop state for the next command.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return Always returns EXIT_SUCCESS (0).
 */
int		ft_shell_loop(t_shell_data *shell_data);

/**
*  _   _ _     _                   
* | | | (_)___| |_ ___  _ __ _   _ 
* | |_| | / __| __/ _ \| '__| | | |
* |  _  | \__ \ || (_) | |  | |_| |
* |_| |_|_|___/\__\___/|_|   \__, |
*                            |___/ 
*/

/**
 * @brief Loads the shell history from a file.
 *
 * Reads each line from the specified file and adds it to the readline history.
 * If the file does not exist, no history is loaded.
 *
 * @param file_path Path to the history file.
 */
void	ft_load_history_from_file(const char *file_path);

/**
 * @brief Saves a command input to the shell history file.
 *
 * Appends the given input line to the specified history file.
 *
 * @param file_path Path to the history file.
 * @param input    The input line to save.
 */
void	ft_save_history_to_file(const char *file_path, const char *input);

/**
 * @brief Adds a command input to the in-memory shell history and saves it to
 *  file.
 *
 * Adds the input to the readline history and saves it to the shell's history
 * file,
 * if the input is not empty and not a duplicate of the last entry.
 *
 * @param input       The input line to add.
 * @param shell_data  Pointer to the main shell data structure
 *  (for history path).
 */
void	ft_add_to_history(const char *input, t_shell_data *shell_data);

/**
 * @brief Generates the path to the shell history file based on the current
 *  working directory.
 *
 * Attempts to create a history file path in the user's home directory. If not
 * possible, returns a default history file name.
 *
 * @param pwd Current working directory.
 * @return Pointer to the allocated history file path string
 * (must be freed by the caller).
 */
char	*ft_make_history_path(const char *pwd);

#endif
