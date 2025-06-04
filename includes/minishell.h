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

void	init_stri(int index, int j, t_shell_data *shell_data);
char	*char_to_str(char c);
int		after_dol_lenght(char *str, int j);
void	free_things(char *tmp2, t_shell_data *shell_data, int index);
void	print_parser(t_commands_list commands_list);

int		question_mark(char **tmp);
int		(*ft_get_builtin_function(char *str))
(t_shell_data *shell_data, t_commands_list *simple_cmd);

#endif
