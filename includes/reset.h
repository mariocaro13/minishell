#ifndef RESET_H
# define RESET_H

/**
 * @file reset.h
 * @brief Function declarations for resetting shell state and loop in minishell.
 *
 * Provides functions to reset the shell's internal state and to reset the
 * shell loop, clearing resources and reinitializing data as needed.
 */

/**
 * @brief Resets the shell's internal state to default values.
 *
 * This function:
 *   - Reinitializes shell data structures and global state.
 *   - Resets environment paths and signal handlers.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_reset_shell_state(t_shell_data *shell_data);

/**
 * @brief Resets the shell loop, clearing commands and input.
 *
 * This function:
 *   - Clears the command list and input arguments.
 *   - Frees process ID array and paths.
 *   - Calls ft_reset_shell_state to reinitialize the shell.
 *   - Sets the reset flag and restarts the shell loop.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return Always returns 1 (used to break out of the current loop).
 */
int		ft_reset_shell_loop(t_shell_data *shell_data);

#endif
