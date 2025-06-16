#ifndef PARSER_H
# define PARSER_H

/**
 * @file parser.h
 * @brief Function declarations for parsing the lexer list into command
 * structures in minishell.
 *
 * Provides functions for initializing parser data, handling redirections,
 * building command lists, and managing command list memory.
 */

/**
 *  ____                          
 * |  _ \ __ _ _ __ ___  ___ _ __ 
 * | |_) / _` | '__/ __|/ _ \ '__|
 * |  __/ (_| | |  \__ \  __/ |   
 * |_|   \__,_|_|  |___/\___|_|   
 */

/**
 * @brief Parses the lexer list and builds the command list for execution.
 *
 * Iterates through the lexer list, splits commands by pipes,
 * processes redirections, and builds the command list structure.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int				ft_parse_lexer_list(t_shell_data *shell_data);

/**
 * @brief Initializes a parser data structure with the given lexer list and
 * shell data.
 *
 * Sets up the parser data for use in command building and redirection handling.
 *
 * @param lexer_list Pointer to the lexer list.
 * @param shell_data Pointer to the main shell data structure.
 * @return Initialized parser data structure.
 */
t_parser_data	ft_init_parser_data(t_lexer_list *lexer_list,
					t_shell_data *shell_data);

/**
*  ____          _ _               _   _                 
* |  _ \ ___  __| (_)_ __ ___  ___| |_(_) ___  _ __  ___ 
* | |_) / _ \/ _` | | '__/ _ \/ __| __| |/ _ \| '_ \/ __|
* |  _ <  __/ (_| | | | |  __/ (__| |_| | (_) | | | \__ \
* |_| \_\___|\__,_|_|_|  \___|\___|\__|_|\___/|_| |_|___/
*/

/**
 * @brief Adds a redirection node to the parser's redirection list.
 *
 * Creates a new redirection node from the lexer and appends it to the parser's
 * redirections. Removes the redirection and its target from the lexer list.
 *
 * @param tmp Pointer to the lexer node representing the redirection.
 * @param parser_data Pointer to the parser data structure.
 * @return 0 on success, or calls error handler on failure.
 */
int				ft_add_redirection(t_lexer_list *tmp,
					t_parser_data *parser_data);

/**
 * @brief Removes all redirection nodes from the parser's lexer list and adds
 * them to the redirection list.
 *
 * Iterates through the lexer list, processes redirections, and updates the
 * parser data.
 *
 * @param parser_data Pointer to the parser data structure.
 */
void			ft_remove_redirections(t_parser_data *parser_data);

/**
*   ____                                          _     
*  / ___|___  _ __ ___  _ __ ___   __ _ _ __   __| |___ 
* | |   / _ \| '_ ` _ \| '_ ` _ \ / _` | '_ \ / _` / __|
* | |__| (_) | | | | | | | | | | | (_| | | | | (_| \__ \
*  \____\___/|_| |_| |_|_| |_| |_|\__,_|_| |_|\__,_|___/
*/

/**
 * @brief Builds a command node from the parser data.
 *
 * Extracts arguments and redirections from the parser data and creates a
 * command list node.
 *
 * @param parser_data Pointer to the parser data structure.
 * @return Pointer to the new command list node, or NULL on allocation failure.
 */
t_command_list	*ft_build_command(t_parser_data *parser_data);

/**
 * @brief Gets the lexer node for the next command (after a pipe).
 *
 * Finds the next PIPE token in the lexer list and returns the node after it.
 *
 * @param lexer_lst Pointer to the current lexer list node.
 * @return Pointer to the next command's lexer node, or NULL if none.
 */
t_lexer_list	*ft_get_next_command(t_lexer_list *lexer_lst);

/**
*     _       _     _    ____                                          _     
*    / \   __| | __| |  / ___|___  _ __ ___  _ __ ___   __ _ _ __   __| |___ 
*   / _ \ / _` |/ _` | | |   / _ \| '_ ` _ \| '_ ` _ \ / _` | '_ \ / _` / __|
*  / ___ \ (_| | (_| | | |__| (_) | | | | | | | | | | | (_| | | | | (_| \__ \
* /_/   \_\__,_|\__,_|  \____\___/|_| |_| |_|_| |_| |_|\__,_|_| |_|\__,_|___/
*/

/**
 * @brief Builds a command node from the current lexer list and parser data.
 *
 * Initializes parser data, builds the command node, and returns it.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param parser_data Pointer to the parser data structure.
 * @return Pointer to the new command list node.
 */
t_command_list	*ft_build_command_node(t_shell_data *shell_data,
					t_parser_data *parser_data);

/**
 * @brief Appends a command node to the shell's command list.
 *
 * Adds the new command node to the end of the command list.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param cmd_node Pointer to the command node to append.
 */
void			ft_command_list_append_node(t_shell_data *shell_data,
					t_command_list *cmd_node);

/**
 * @brief Creates a new command list node with the given arguments
 * and redirections.
 *
 * Allocates and initializes a command list node.
 *
 * @param str Array of command argument strings.
 * @param num_redirections Number of redirections for this command.
 * @param redirections Pointer to the redirection lexer list.
 * @return Pointer to the new command list node, or NULL on allocation failure.
 */
t_command_list	*ft_command_list_create_node(char **str, int num_redirections,
					t_lexer_list *redirections);

/**
 * @brief Gets the first node in a command list.
 *
 * @param map Pointer to the command list.
 * @return Pointer to the first node in the list.
 */
t_command_list	*ft_command_list_get_first(t_command_list *map);

/**
 * @brief Adds a command node to the end of the command list.
 *
 * @param lst Pointer to the command list pointer.
 * @param new Pointer to the new command node to add.
 */
void			ft_command_list_add_node_back(t_command_list **lst,
					t_command_list *new);

/**
*  ____       _    ____                                          _     
* |  _ \  ___| |  / ___|___  _ __ ___  _ __ ___   __ _ _ __   __| |___ 
* | | | |/ _ \ | | |   / _ \| '_ ` _ \| '_ ` _ \ / _` | '_ \ / _` / __|
* | |_| |  __/ | | |__| (_) | | | | | | | | | | | (_| | | | | (_| \__ \
* |____/ \___|_|  \____\___/|_| |_| |_|_| |_| |_|\__,_|_| |_|\__,_|___/
*/

/**
 * @brief Deletes the first node in the command list.
 *
 * Frees the node and its resources, and updates the list pointer.
 *
 * @param command_list Pointer to the command list pointer.
 */
void			ft_command_list_del_first(t_command_list **command_list);

/**
 * @brief Frees all nodes in the command list and sets the pointer to NULL.
 *
 * Frees arguments, redirections, and heredoc file names for each node.
 *
 * @param command_list Pointer to the command list pointer.
 */
void			ft_command_list_clear(t_command_list **command_list);

#endif
