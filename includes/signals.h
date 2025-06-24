/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:37 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:38 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/**
 * @file signals.h
 * @brief Function declarations for signal handling in minishell.
 *
 * Provides handlers for SIGINT and SIGQUIT, and a readline event hook
 * for proper terminal behavior during shell operation.
 */

/**
 * @brief Readline event hook for custom event handling.
 *
 * Used to integrate custom event processing with the readline library.
 * Returns EXIT_SUCCESS to indicate successful handling.
 *
 * @return EXIT_SUCCESS (0).
 */
int		ft_rl_event_hook(void);

/**
 * @brief Signal handler for SIGINT (Ctrl+C).
 *
 * Handles interruption signals during shell operation and heredoc input.
 * If in heredoc, sets rl_done to 1 to stop input. Otherwise, prints a new line,
 * clears the current input, and refreshes the prompt.
 *
 * @param signum The signal number (unused).
 */
void	ft_sigint_handler(int signum);

/**
 * @brief Signal handler for SIGQUIT (Ctrl+\).
 *
 * Handles quit signals by printing a message and refreshing the prompt.
 *
 * @param signum The signal number (unused).
 */
void	ft_sigquit_handler(int signum);

#endif
