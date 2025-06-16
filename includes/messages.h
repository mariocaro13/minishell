#ifndef MESSAGES_H
# define MESSAGES_H

/**
 * @file messages.h
 * @brief Defines all user-facing messages, prompts, and error strings for
 * minishell.
 *
 * This header centralizes all string literals used for prompts,
 * welcome banners, usage instructions, heredoc prompts, and error messages,
 * including color formatting.
 */

// Usage and prompts
# define MSG_USAGE "\033[33mUsage: ./minishell\033[0m\n"
# define MSG_DEFAULT_PROMPT "M&Mshell> "
# define MSG_PWD_PROMPT "M&Mshell:"
# define MSG_EXIT "exit"
# define MSG_HEREDOC	"> "

// Welcome banner (multi-line, colored ASCII art)
# define MSG_WELCOME "\033[91m\n\
╔══════════════════════════════════════════════════════════════════════════════╗\n\
║                                                                              ║\n\
║              \033[38;5;180m█▄ ▄█ █▄ ▄█ █▄ ▄█   █▀█ █▀█ █▀▀ █▀ █▀▀ █▄░█ ▀█▀ █▀              \033[0;31m║\n\
║              \033[38;5;130m█ ▀ █   █░  █ ▀ █   █▀▀ █▀▄ ██▄ ▄█ ██▄ █░▀█ ░█░ ▄█              \033[0;31m║\n\
║                                                                              ║\n\
║   \033[0;1;31m███╗   ███╗\033[1;5;37m   ██╗   \033[0;1;33m███╗   ███╗\033[0;5;96m ██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░    \033[0;31m║\n\
║   \033[0;1;31m████╗ ████║\033[1;5;37m   ██║   \033[0;1;33m████╗ ████║\033[0;5;96m██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░    \033[0;31m║\n\
║   \033[0;31m██╔████╔██║\033[0;5;37m████████╗\033[0;1;33m██╔████╔██║\033[0;5;96m╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░    \033[0;31m║\n\
║   \033[0;31m██║╚██╔╝██║\033[1;5;37m██╔═██╔═╝\033[0;33m██║╚██╔╝██║\033[0;5;96m ╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░    \033[0;31m║\n\
║   \033[0;31m██║ ╚═╝ ██║\033[0;5;37m██████║  \033[0;33m██║ ╚═╝ ██║\033[0;5;96m██████╔╝██║░░██║███████╗███████╗███████╗    \033[0;31m║\n\
║   \033[0;91m╚═╝     ╚═╝\033[0;5;67m╚═════╝  \033[0;1;33m╚═╝     ╚═╝\033[0;5;36m╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝    \033[0;31m║\n\
║                                                                              ║\n\
╚══════════════════════════════════════════════════════════════════════════════╝\
\033[0m\n\n"

// Error messages
# define MSG_ERR_INIT "Error initializing shell.\n"
# define MSG_ERR_OPEN_FD "Error: error opening file.\n"
# define MSG_ERR_SYNTAX "Syntax error: unexpected token.\n"
# define MSG_ERR_SYNTAX_TOKEN "Syntax error: unexpected token: "
# define MSG_ERR_MEMORY "Memory error: unable to assign memory.\n"
# define MSG_ERR_QUOTE "Quote error: unable to locate closing quote.\n"
# define MSG_ERR_PARSER "Parser error.\n"
# define MSG_ERR_PIPE "Pipe error: unable to create pipe.\n"
# define MSG_ERR_FORK "Fork error.\n"
# define MSG_ERR_REDIRECT_OUT "Outfile: error.\n"
# define MSG_ERR_REDIRECT_IN "Infile: no such file or directory: "
# define MSG_ERR_PATH "Path error: path does not exist.\n"
# define MSG_ERR_CMD_NOT_FOUND ": command not found.\n"
# define MSG_ERR_CD_ARGS "Error: cd: invalid arguments."
# define MSG_ERR_CD_FILE "Error: cd: No such file or directory: "
# define MSG_ERR_UNSET_INVALID_ID "Error: unset: not a valid identifier."
# define MSG_ERR_UNSET_NOT_ENOUGH_ARGS "Error: unset: not enough arguments."

#endif
