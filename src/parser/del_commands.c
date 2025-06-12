#include "minishell.h"

void	ft_command_list_del_first(t_commands_list **command_list)
{
	t_commands_list	*next_node;

	if (!command_list || !*command_list)
		return ;
	next_node = (*command_list)->next;
	ft_lexer_clear(&(*command_list)->redirections);
	free(*command_list);
	*command_list = next_node;
}

void	ft_command_list_clear(t_commands_list **command_list)
{
	t_commands_list	*next_node;
	t_lexer_list	*redirections_tmp;

	if (!*command_list)
		return ;
	while (*command_list)
	{
		next_node = (*command_list)->next;
		redirections_tmp = (*command_list)->redirections;
		ft_lexer_clear(&redirections_tmp);
		if ((*command_list)->str)
		{
			ft_free_array((*command_list)->str);
			(*command_list)->str = NULL;
		}
		if ((*command_list)->hd_file_name)
		{
			free((*command_list)->hd_file_name);
			(*command_list)->hd_file_name = NULL;
		}
		free(*command_list);
		*command_list = next_node;
	}
	*command_list = NULL;
}
