/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:00 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:02 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/**
 * @file data.h
 * @brief Defines the main data structures used throughout the minishell project.
 */

/**
 * @var g_is_in_heredoc
 * @brief Global flag indicating if the shell is currently processing a heredoc.
 */
extern bool						g_is_in_heredoc;

// Forward declarations for struct dependencies
typedef struct s_lexer_list		t_lexer_list;
typedef struct s_command_list	t_command_list;

/**
 * @struct s_shell_state
 * @brief Represents the global state of the shell.
 *
 * @var should_stop_heredoc  Flag indicating if heredoc processing should be
 * stopped.
 * @var is_in_cmd            Flag indicating if the shell is currently executing
 * a command.
 * @var error_num            The last error number encountered by the shell.
 */
typedef struct s_shell_state
{
	bool	should_stop_heredoc;
	bool	is_in_cmd;
	int		error_num;
}	t_shell_state;

/**
 * @struct s_shell_data
 * @brief Main structure representing the shell session and its state.
 *
 * @var args           Command-line input as a single string.
 * @var paths          Array of directories for command lookup (from PATH).
 * @var envp           Array of environment variables.
 * @var command_list   Pointer to the list of parsed commands to execute.
 * @var lexer_list     Pointer to the list of lexer tokens.
 * @var pwd            Current working directory.
 * @var old_pwd        Previous working directory.
 * @var pipes          Number of pipes in the current command.
 * @var pid            Array of process IDs for child processes.
 * @var heredoc        Flag indicating if heredoc is active.
 * @var reset          Flag indicating if the shell state should be reset.
 * @var history_path   Path to the shell history file.
 * @var state          Embedded shell state structure (errors, heredoc, etc).
 */
typedef struct s_shell_data
{
	char			*args;
	char			**paths;
	char			**envp;
	t_command_list	*command_list;
	t_lexer_list	*lexer_list;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				*pid;
	bool			heredoc;
	bool			reset;
	char			*history_path;
	t_shell_state	state;
}	t_shell_data;

/**
 * @struct s_parser_data
 * @brief Structure used during parsing to build command lists.
 *
 * @var lexer_list        Pointer to the current lexer token list.
 * @var redirections      Pointer to the list of redirection tokens.
 * @var num_redirections  Number of redirections in the current command.
 * @var shell_data        Pointer to the main shell data structure.
 */
typedef struct s_parser_data
{
	t_lexer_list	*lexer_list;
	t_lexer_list	*redirections;
	int				num_redirections;
	t_shell_data	*shell_data;
}	t_parser_data;

/**
 * @struct s_command_list
 * @brief Represents a single command and its associated data.
 *
 * @var str                Array of command arguments (argv).
 * @var builtin            Pointer to the builtin function (if applicable).
 * @var num_redirections   Number of redirections for this command.
 * @var heredoc_file_name  Name of the heredoc temporary file (if used).
 * @var redirections       Pointer to the list of redirection tokens.
 * @var next               Pointer to the next command in the list.
 * @var prev               Pointer to the previous command in the list.
 */
typedef struct s_command_list
{
	char			**str;
	int				(*builtin)(t_shell_data *, struct s_command_list *);
	int				num_redirections;
	char			*heredoc_file_name;
	t_lexer_list	*redirections;
	t_command_list	*next;
	t_command_list	*prev;
}	t_command_list;

/**
 * @enum e_token
 * @brief Enumerates the possible token types in the shell.
 *
 * @var WORD                A word (command or argument).
 * @var PIPE                A pipe symbol '|'.
 * @var REDIRECT_OUT        Output redirection '>'.
 * @var REDIRECT_OUT_APPEND Output append redirection '>>'.
 * @var REDIRECT_IN         Input redirection '<'.
 * @var REDIRECT_HEREDOC    Heredoc redirection '<<'.
 * @var QUOTE               Single quote '\''.
 * @var QUOTE_DOUBLE        Double quote '"'.
 */
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

/**
 * @enum s_error
 * @brief Enumerates possible error types in the shell.
 *
 * @var ERR_OPEN_FD         Error opening a file descriptor.
 * @var ERR_SYNTAX          Syntax error.
 * @var ERR_MEMORY          Memory allocation error.
 * @var ERR_QUOTE           Unclosed quote error.
 * @var ERR_PARSER          Parser error.
 * @var ERR_PIPE            Pipe creation error.
 * @var ERR_FORK            Fork error.
 * @var ERR_REDIRECT_OUT    Output redirection error.
 * @var ERR_REDIRECT_IN     Input redirection error.
 * @var ERR_PATH            Path resolution error.
 */
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
