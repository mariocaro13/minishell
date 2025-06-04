#ifndef MESSAGES_H
# define MESSAGES_H

# define MSG_USAGE "\033[33mUsage: ./minishell\033[0m\n"

# define MSG_PROMPT "M&Mshell> "

# define MSG_EXIT "exit"

# define MSG_HEREDOC	"\033[1;34m> \033[0m"

// WELCOME
# define MSG_WELCOME "\033[91m\n\
╔══════════════════════════════════════════════════════════════════════════════╗\n\
║                                                                              ║\n\
║              \033[91m█▄ ▄█ █▄ ▄█ █▄ ▄█   █▀█ █▀█ █▀▀ █▀ █▀▀ █▄░█ ▀█▀ █▀              \033[31m║\n\
║              \033[31m█ ▀ █   █░  █ ▀ █   █▀▀ █▀▄ ██▄ ▄█ ██▄ █░▀█ ░█░ ▄█              \033[31m║\n\
║                                                                              ║\n\
║   \033[93m███╗░░░███╗░░░██╗░░░███╗░░░███╗░░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░   \033[31m║\n\
║   \033[93m████╗░████║░░░██║░░░████╗░████║░██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░   \033[31m║\n\
║   \033[93m██╔████╔██║████████╗██╔████╔██║░╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░   \033[31m║\n\
║   \033[93m██║╚██╔╝██║██╔═██╔═╝██║╚██╔╝██║░░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░   \033[31m║\n\
║   \033[93m██║░╚═╝░██║██████║░░██║░╚═╝░██║░██████╔╝██║░░██║███████╗███████╗███████╗   \033[31m║\n\
║   \033[93m╚═╝░░░░░╚═╝╚═════╝░░╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝   \033[31m║\n\
║                                                                              ║\n\
╚══════════════════════════════════════════════════════════════════════════════╝\
\033[0m\n\n"

// HISTORY
# define HISTORY_FD "minishell_history.txt"

// ERROR MSG
# define MSG_ERR_INIT "Error initializing shell\n"
# define MSG_ERR_OPEN_FD "Error: error opening file\n"
# define MSG_ERR_SYNTAX "Syntax error: unexpected token\n"
# define MSG_ERR_SYNTAX_TOKEN "Syntax error: unexpected token: "
# define MSG_ERR_MEMORY "Memory error: unable to assign memory\n"
# define MSG_ERR_QUOTE "Quote error: unable to locate closing quote\n"
# define MSG_ERR_PARSER "Parser error\n"
# define MSG_ERR_PIPE "Pipe error: unable to create pipe\n"
# define MSG_ERR_FORK "Fork error\n"
# define MSG_ERR_REDIRECT_OUT "Outfile error\n"
# define MSG_ERR_REDIRECT_IN "Infile error: no such file or directory\n"
# define MSG_ERR_PATH "Path error: path does not exist\n"
# define MSG_ERR_CMD_NOT_FOUND ": command not found\n"\

#endif
