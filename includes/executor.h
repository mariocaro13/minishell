#ifndef EXECUTOR_H
# define EXECUTOR_H

/**
 * @file executor.h
 * @brief Function declarations for command execution, redirections,
 * pipelines, and heredoc handling in minishell.
 *
 * This header provides prototypes for all functions related to executing
 * commands,
 * handling pipelines, redirections, and heredoc functionality.
 */

/**
 *   ____ _               _                               
 *  / ___| |__   ___  ___| | __                           
 * | |   | '_ \ / _ \/ __| |/ /                           
 * | |___| | | |  __/ (__|   <                            
 *  \____|_| |_|\___|\___|_|\_\     _   _                 
 * |  _ \ ___  __| (_)_ __ ___  ___| |_(_) ___  _ __  ___ 
 * | |_) / _ \/ _` | | '__/ _ \/ __| __| |/ _ \| '_ \/ __|
 * |  _ <  __/ (_| | | | |  __/ (__| |_| | (_) | | | \__ \
 * |_| \_\___|\__,_|_|_|  \___|\___|\__|_|\___/|_| |_|___/
 */

/**
 * @brief Handles all input/output redirections for a command.
 *
 * Iterates over the redirections list in the command and applies each
 * redirection.
 * Handles input, output, append, and heredoc redirections.
 *
 * @param cmd Pointer to the command list node.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_handle_redirections(t_command_list *cmd);

/**
 * @brief Opens an output file for writing or appending, based on the redirection
 * type.
 *
 * @param redirections Pointer to the redirection lexer node.
 * @return File descriptor on success, -1 on error.
 */
int		ft_check_append_outfile(t_lexer_list *redirections);

/**
 * @brief Opens an input file and sets it as STDIN.
 *
 * Prints an error and returns EXIT_FAILURE if the file cannot be opened.
 *
 * @param file_name Name of the file to open.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_handle_infile(char *file_name);

/**
 * @brief Opens an output file and sets it as STDOUT.
 *
 * Handles both truncating and appending modes.
 *
 * @param redirection Pointer to the redirection lexer node.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_handle_outfile(t_lexer_list *redirection);

/**
 *  _____                     _             
 * | ____|_  _____  ___ _   _| |_ ___  _ __ 
 * |  _| \ \/ / _ \/ __| | | | __/ _ \| '__|
 * | |___ >  <  __/ (__| |_| | || (_) | |   
 * |_____/_/\_\___|\___|\__,_|\__\___/|_|   
 */

/**
 * @brief Executes all commands in the shell, handling pipelines if present.
 *
 * Sets up signals, manages command execution, and resets shell state after
 * execution.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_execute_commands(t_shell_data *shell_data);

/**
 * @brief Executes a pipeline of commands.
 *
 * Sets up pipes, forks processes, and manages input/output for each command
 * in the pipeline.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_execute_pipeline_command(t_shell_data *shell_data);

/**
 * @brief Waits for all processes in a pipeline to finish.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param pid Array of process IDs.
 * @param amount Number of processes to wait for.
 * @return EXIT_SUCCESS.
 */
int		ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount);

/**
 *  _   _                 _ _                            
 * | | | | __ _ _ __   __| | | ___                       
 * | |_| |/ _` | '_ \ / _` | |/ _ \                      
 * |  _  | (_| | | | | (_| | |  __/                      
 * |_|_|_|\__,_|_| |_|\__,_|_|\___|                _     
 *  / ___|___  _ __ ___  _ __ ___   __ _ _ __   __| |___ 
 * | |   / _ \| '_ ` _ \| '_ ` _ \ / _` | '_ \ / _` / __|
 * | |__| (_) | | | | | | | | | | | (_| | | | | (_| \__ \
 *  \____\___/|_| |_| |_|_| |_| |_|\__,_|_| |_|\__,_|___/
 */

/**
 * @brief Finds and executes a command, searching in PATH if necessary.
 *
 * @param cmd Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return Exit code of the executed command.
 */
int		ft_find_command(t_command_list *cmd, t_shell_data *shell_data);

/**
 * @brief Executes a single command, handling builtins and external commands.
 *
 * Handles redirections, builtins, and external command execution.
 *
 * @param cmd Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return Exit code of the executed command.
 */
int		ft_execute_command(t_command_list *cmd, t_shell_data *shell_data);

/**
 * @brief Duplicates file descriptors for a command in a pipeline.
 *
 * Sets up STDIN and STDOUT for the command based on the pipeline.
 *
 * @param cmd Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @param end Pipe file descriptors.
 * @param fd_in Input file descriptor.
 */
void	ft_dup_command(t_command_list *cmd, t_shell_data *shell_data,
			int end[2], int fd_in);

/**
 * @brief Handles the execution of a command, including expansion and builtins.
 *
 * Expands variables, checks if the command is a builtin, and executes it.
 *
 * @param cmd Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_handle_command(t_command_list *cmd, t_shell_data *shell_data);

/**
 *  _   _                   _            
 * | | | | ___ _ __ ___  __| | ___   ___ 
 * | |_| |/ _ \ '__/ _ \/ _` |/ _ \ / __|
 * |  _  |  __/ | |  __/ (_| | (_) | (__ 
 * |_| |_|\___|_|  \___|\__,_|\___/ \___|
 */

/**
 * @brief Handles heredoc redirections for a command.
 *
 * Processes all heredoc tokens in the command, creates temporary files,
 * and manages heredoc state.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param cmd Pointer to the command list node.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_handle_heredoc(t_shell_data *shell_data, t_command_list *cmd);

/**
 * @brief Creates a unique filename for a heredoc temporary file.
 *
 * @return Pointer to the allocated filename string
 * (must be freed by the caller).
 */
char	*ft_create_heredoc_filename(void);

/**
 * @brief Gets the file descriptor for a heredoc file and sets it as STDIN.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param end Pipe file descriptors.
 * @param cmd Pointer to the command list node.
 * @return File descriptor for the heredoc file.
 */
int		ft_get_fd_heredoc(t_shell_data *shell_data, int end[2],
			t_command_list *cmd);

#endif
