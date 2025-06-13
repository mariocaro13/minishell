#ifndef MINISHELL_H
# define MINISHELL_H

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

// Loop
int		ft_shell_loop(t_shell_data *shell_data);

// History
void	ft_load_history_from_file(const char *filename);
void	ft_save_history_to_file(const char *filename, const char *input);
void	ft_add_to_history(const char *input, t_shell_data *shell_data);
char	*ft_make_history_path(const char *pwd);

#endif
