/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:05 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:07 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/**
 * @file error.h
 * @brief Function declarations for error handling and error message
 * utilities in minishell.
 *
 * Provides functions to handle parser errors, print error messages
 * for various shell errors, and manage error states related to tokens,
 * commands, and builtins.
 */

/**
 *  _____                       _   _                 _ _             
 * | ____|_ __ _ __ ___  _ __  | | | | __ _ _ __   __| | |_ __   __ _ 
 * |  _| | '__| '__/ _ \| '__| | |_| |/ _` | '_ \ / _` | | '_ \ / _` |
 * | |___| |  | | | (_) | |    |  _  | (_| | | | | (_| | | | | | (_| |
 * |_____|_|  |_|  \___/|_|    |_| |_|\__,_|_| |_|\__,_|_|_| |_|\__, |
 *                                                              |___/ 
 */

/**
 * * @brief Handles a parser error by clearing lexer and command lists and
 * printing an error message.
 *
 * @param error Error code (see t_error enum).
 * @param shell_data Pointer to the main shell data structure.
 * @param lexer_list Pointer to the lexer list to clear.
 */
void	ft_error_parser(int error, t_shell_data *shell_data,
			t_lexer_list *lexer_list);

/**
 * @brief Handles a parser error related to a specific token.
 *
 * Prints a syntax error message for the given token, clears the lexer list,
 * resets the shell loop, and returns EXIT_FAILURE.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param lexer_list Pointer to the lexer list to clear.
 * @param token The token that caused the error.
 * @return EXIT_FAILURE.
 */
int		ft_error_parser_token(t_shell_data *shell_data,
			t_lexer_list *lexer_list, t_token token);

/**
 * @brief Handles pipe-related errors in the shell.
 *
 * If the token is a pipe or the lexer list is empty, prints an error and resets
 * the shell loop.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param token The token to check.
 * @return EXIT_FAILURE on error, EXIT_SUCCESS otherwise.
 */
int		ft_error_pipe_handler(t_shell_data *shell_data, t_token token);

/**
 *  _____                       __  __                                
 * | ____|_ __ _ __ ___  _ __  |  \/  | ___  ___ ___  __ _  __ _  ___ 
 * |  _| | '__| '__/ _ \| '__| | |\/| |/ _ \/ __/ __|/ _` |/ _` |/ _ \
 * | |___| |  | | | (_) | |    | |  | |  __/\__ \__ \ (_| | (_| |  __/
 * |_____|_|  |_|  \___/|_|    |_|  |_|\___||___/___/\__,_|\__, |\___|
 *                                                         |___/      
 */

/**
 * @brief Prints a syntax error message for a specific token.
 *
 * @param token The token that caused the syntax error.
 */
void	ft_error_print_msg_token(t_token token);

/**
 * @brief Handles and prints a general error message based on the error code.
 *
 * Also resets the shell loop after printing the error.
 *
 * @param error Error code (see t_error enum).
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_FAILURE.
 */
int		ft_error_handle_msg(int error, t_shell_data *shell_data);

/**
 * @brief Prints an error message for a command not found.
 *
 * @param str The command string that was not found.
 * @return 127 (standard shell return code for command not found).
 */
int		ft_error_print_command_not_found(char *str);

/**
 * @brief Prints an error message for an invalid export identifier.
 *
 * @param c The invalid identifier string.
 * @return EXIT_FAILURE.
 */
int		ft_error_print_export(char *c);

/**
 * @brief Prints an error message for an invalid unset identifier (with slash).
 *
 * @param command_list Pointer to the command list containing the invalid
 * identifier.
 */
void	ft_error_print_unset_slash_error(t_command_list *command_list);

#endif
