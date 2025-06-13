#ifndef PARSER_H
# define PARSER_H

typedef struct s_parser_data
{
	t_lexer_list	*lexer_list;
	t_lexer_list	*redirections;
	int				num_redirections;
	t_shell_data	*shell_data;
}	t_parser_data;

// Parser
int				ft_parse_lexer_list(t_shell_data *shell_data);
t_parser_data	ft_init_parser_data(t_lexer_list *lexer_list,
					t_shell_data *shell_data);

//handle_redirections
int				ft_add_redirection(t_lexer_list *tmp,
					t_parser_data *parser_tools);
void			ft_remove_redirections(t_parser_data *parser_tools);

// Commands
t_command_list	*ft_build_command(t_parser_data *parser_tools);
t_lexer_list	*ft_get_next_command(t_lexer_list *lexer_lst);

// Add commands
t_command_list	*ft_build_command_node(t_shell_data *shell_data,
					t_parser_data *parser_data);
void			ft_command_list_append_node(t_shell_data *shell_data,
					t_command_list *cmd_node);
t_command_list	*ft_command_list_create_node(char **str, int num_redirections,
					t_lexer_list *redirections);
t_command_list	*ft_command_list_get_first(t_command_list *map);
void			ft_command_list_add_node_back(t_command_list **lst,
					t_command_list *new);

// Del commands
void			ft_command_list_del_first(t_command_list **lst);
void			ft_command_list_clear(t_command_list **lst);

#endif
