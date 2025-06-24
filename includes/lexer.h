/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:25 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:26 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/**
 * @file lexer.h
 * @brief Function declarations and data structures for lexical analysis
 * in minishell.
 *
 * Provides functions for creating, managing, and freeing lexer nodes,
 * building token lists, and handling tokenization of input strings.
 */

/**
 * @struct s_lexer_list
 * @brief Doubly-linked list node representing a token in the input.
 *
 * @var str   The string value of the token.
 * @var token The token type (see t_token).
 * @var index The index of the token in the input.
 * @var next  Pointer to the next token node.
 * @var prev  Pointer to the previous token node.
 */
typedef struct s_lexer_list
{
	char			*str;
	t_token			token;
	int				index;
	t_lexer_list	*next;
	t_lexer_list	*prev;
}	t_lexer_list;

// Lexer node management

/**
 * @brief Frees the string in a lexer node and sets it to NULL.
 *
 * @param node Pointer to the lexer node.
 */
void			ft_free_node_str(t_lexer_list *node);

/**
 * @brief Finds a lexer node by its index in the list.
 *
 * @param lexer_list Pointer to the start of the lexer list.
 * @param index Index to search for.
 * @param prev Output: pointer to the previous node.
 * @param found Output: pointer to the found node.
 */
void			ft_lexer_find_node_by_index(t_lexer_list *lexer_list, int index,
					t_lexer_list **prev, t_lexer_list **found);

/**
 * @brief Frees all nodes in a lexer list and sets the pointer to NULL.
 *
 * @param lexer_list Pointer to the lexer list pointer.
 */
void			ft_lexer_clear(t_lexer_list **lexer_list);

/**
 * @brief Counts the number of argument tokens (WORD) before a pipe or end.
 *
 * @param lexer_list Pointer to the lexer list.
 * @return Number of argument tokens.
 */
int				ft_lexer_count_args(t_lexer_list *lexer_list);

// Add lexer

/**
 * @brief Creates a new lexer node with the given string and token type.
 *
 * @param str String value for the token.
 * @param token Token type.
 * @return Pointer to the new lexer node, or NULL on allocation failure.
 */
t_lexer_list	*ft_lexer_create_node(char *str, int token);

/**
 * @brief Appends a lexer node to the end of the lexer list.
 *
 * @param lexer_list Pointer to the lexer list pointer.
 * @param node Node to append.
 */
void			ft_lexer_append_node(t_lexer_list **lexer_list,
					t_lexer_list *node);

/**
 * @brief Adds a token to the lexer list, creating a new node.
 *
 * @param str String value for the token.
 * @param token_type Token type.
 * @param lexer_list Pointer to the lexer list pointer.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on allocation failure.
 */
int				ft_add_token_to_lexer(char *str, t_token token_type,
					t_lexer_list **lexer_list);

// Del lexer

/**
 * @brief Frees a lexer node and sets its pointer to NULL.
 *
 * @param lexer_list Pointer to the lexer node pointer.
 * @return NULL always.
 */
t_lexer_list	*ft_lexer_free_node(t_lexer_list **lexer_list);

/**
 * @brief Deletes the first node in the lexer list.
 *
 * @param lexer_list Pointer to the lexer list pointer.
 */
void			ft_lexer_del_first_node(t_lexer_list **lexer_list);

/**
 * @brief Deletes a lexer node by its index.
 *
 * @param lst Pointer to the lexer list pointer.
 * @param index Index of the node to delete.
 */
void			ft_lexer_del_by_index(t_lexer_list **lst, int index);

// Tokenization

/**
 * @brief Builds the token list from the shell input string.
 *
 * Tokenizes the input and fills the lexer list with tokens.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return true on success, false on error.
 */
bool			ft_build_token_list(t_shell_data *shell_data);

// Handle_token

/**
 * @brief Determines the token type at a given index in the input string.
 *
 * @param str Input string.
 * @param index Index to check.
 * @return Token type at the given index.
 */
t_token			ft_get_token_type(const char *str, int index);

/**
 * @brief Handles tokenization at a given index, adding the token to the lexer
 * list.
 *
 * @param str Input string.
 * @param index Index to start tokenization.
 * @param lexer_list Pointer to the lexer list pointer.
 * @return Length of the token processed, or -1 on error.
 */
int				ft_handle_token(char *str, int index,
					t_lexer_list **lexer_list);
// Word

/**
 * @brief Tokenizes a word starting at the given index and adds it to the lexer
 * list.
 *
 * @param start Start index of the word.
 * @param str Input string.
 * @param lexer_list Pointer to the lexer list pointer.
 * @return Length of the word tokenized, or -1 on error.
 */
int				ft_tokenize_word(int start, char *str,
					t_lexer_list **lexer_list);

#endif
