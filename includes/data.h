/**
 * @file data.h
 * @brief Contains data structures and global variables for the minishell
 *  project.
 *
 * This header defines the core data structures used throughout the minishell,
 * including the global shell state and the main shell context.
 */
#ifndef DATA_H
# define DATA_H

// Forwards declarations
typedef struct s_lexer_list		t_lexer_list;
typedef struct s_commands_list	t_commands_list;

/**
 * @struct s_global_shell_state
 * @brief Represents the global state of the shell.
 *
 * @var error_num      The last error number encountered by the shell.
 * @var should_stop_heredoc	Flag indicating if heredoc processing should be
 *  stopped.
 * @var is_in_cmd	Flag indicating if the shell is currently executing a
 *  command.
 * @var is_in_heredoc	Flag indicating if the shell is currently processing a
 *  heredoc.
 */
typedef struct s_global_shell_state
{
	int		error_num;
	bool	should_stop_heredoc;
	bool	is_in_cmd;
	bool	is_in_heredoc;
}	t_global_shell_state;

extern t_global_shell_state		g_shell_state;

/**
 * @struct s_shell_data
 * @brief Main structure representing the shell data.
 *
 * @var args           Command-line arguments as a single string.
 * @var paths          Array of paths for command lookup.
 * @var envp           Array of environment variables.
 * @var commands_list    Pointer to the list of simple commands_list to execute.
 * @var lexer_list     Pointer to the list of lexer tokens.
 * @var pwd            Current working directory.
 * @var old_pwd        Previous working directory.
 * @var pipes          Number of pipes in the current command.
 * @var pid            Array of process IDs for child processes.
 * @var heredoc        Flag indicating if heredoc is active.
 * @var reset          Flag indicating if the shell state should be reset.
 */
typedef struct s_shell_data
{
	char			*args;
	char			**paths;
	char			**envp;
	t_commands_list	*commands_list;
	t_lexer_list	*lexer_list;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				*pid;
	bool			heredoc;
	bool			reset;
}	t_shell_data;

typedef struct s_commands_list
{
	char			**str;
	int				(*builtin)(t_shell_data *, struct s_commands_list *);
	int				num_redirections;
	char			*hd_file_name;
	t_lexer_list	*redirections;
	t_commands_list	*next;
	t_commands_list	*prev;
}	t_commands_list;

typedef enum e_token
{
	WORD = 0,
	PIPE,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_IN,
	REDIRECT_HEREDOC,
	QUOTE,
	QUOTE_DOUBLE,
}	t_token;

typedef enum s_error
{
	ERR_OPEN_FD = 0,
	ERR_SYNTAX,
	ERR_MEMORY,
	ERR_QUOTE,
	ERR_PARSER,
	ERR_PIPE,
	ERR_FORK,
	ERR_REDIRECT_OUT,
	ERR_REDIRECT_IN,
	ERR_PATH,
}	t_error;

#endif
