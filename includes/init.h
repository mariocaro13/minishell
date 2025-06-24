/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:22 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:23 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

/**
 *  ___       _ _     _____            
 * |_ _|_ __ (_) |_  | ____|_ ____   __
 *  | || '_ \| | __| |  _| | '_ \ \ / /
 *  | || | | | | |_  | |___| | | \ V / 
 * |___|_| |_|_|\__| |_____|_| |_|\_/  
 */

/**
 * @brief Initializes the shell's environment variable array.
 *
 * This function:
 *   - Duplicates the envp array into shell_data->envp.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param envp       The environment variables from main().
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_init_shell_envp(t_shell_data *shell_data, char **envp);

/**
 * @brief Initializes the shell's PATH variable and splits it into an array.
 *
 * This function:
 *   - Extracts the PATH variable from shell_data->envp.
 *   - Splits it into shell_data->paths.
 *   - Appends a slash to each path if missing.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_init_env_paths(t_shell_data *shell_data);

/**
 *  ___       _ _     ____  _          _ _ 
 * |_ _|_ __ (_) |_  / ___|| |__   ___| | |
 *  | || '_ \| | __| \___ \| '_ \ / _ \ | |
 *  | || | | | | |_   ___) | | | |  __/ | |
 * |___|_| |_|_|\__| |____/|_| |_|\___|_|_|
 */

/**
 * @brief Initializes the shell's working directories
 * (pwd and oldpwd) from the environment.
 *
 * This function:
 *   - Searches the environment for PWD and OLDPWD variables.
 *   - Sets the shell_data->pwd and shell_data->old_pwd accordingly.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_init_shell_dirs(t_shell_data *shell_data);

/**
 * @brief Initializes the shell_data structure to default values.
 *
 * This function:
 *   - Sets pointers to NULL and numeric fields to 0 or false.
 *   - Prepares the shell_data structure for further initialization.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_init_shell_data(t_shell_data *shell_data);

/**
 * @brief Initializes the global shell state and heredoc flag.
 *
 * This function:
 *   - Resets global state variables (heredoc, is_in_cmd, etc).
 *   - Sets g_is_in_heredoc to false.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
void	ft_init_global_shell_state(t_shell_data *shell_data);

/**
 * @brief Initializes signal handlers for the shell.
 *
 * This function:
 *   - Sets up handlers for SIGINT and SIGQUIT.
 *   - Sets the readline event hook.
 */
void	ft_init_signals(void);

/**
 * @brief Initializes all shell data and environment for the shell session.
 *
 * This function:
 *   - Calls all other initialization routines (data, envp, dirs, paths,
 * signals).
 *   - Cleans up and returns EXIT_FAILURE if any step fails.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param envp       The environment variables from main().
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		ft_init_shell(t_shell_data *shell_data, char **envp);

#endif
