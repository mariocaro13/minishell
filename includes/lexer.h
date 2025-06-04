#ifndef LEXER_H
# define LEXER_H

typedef struct s_lexer_list
{
	char			*str;
	t_token			token;
	int				index;
	t_lexer_list	*next;
	t_lexer_list	*prev;
}	t_lexer_list;

// Lexer
void			ft_free_node_str(t_lexer_list *node);
void			ft_lexer_find_node_by_index(t_lexer_list *lexer_list, int index,
					t_lexer_list **prev, t_lexer_list **found);
void			ft_lexer_clear(t_lexer_list **lexer_list);
int				ft_lexer_count_args(t_lexer_list *lexer_list);

// Add lexer
t_lexer_list	*ft_lexer_create_node(char *str, int token);
void			ft_lexer_append_node(t_lexer_list **lexer_list,
					t_lexer_list *node);
int				ft_add_token_to_lexer(char *str, t_token token_type,
					t_lexer_list **lexer_list);

// Del lexer
t_lexer_list	*ft_lexer_free_node(t_lexer_list **lexer_list);
void			ft_lexer_del_first_node(t_lexer_list **lexer_list);
void			ft_lexer_del_by_index(t_lexer_list **lst, int index);

// token
bool			ft_build_token_list(t_shell_data *shell_data);

// Handle_token
t_token			ft_get_token_type(const char *str, int index);
int				ft_handle_token(char *str, int index,
					t_lexer_list **lexer_list);
// Word
int				ft_tokenize_word(int start, char *str,
					t_lexer_list **lexer_list);

#endif
