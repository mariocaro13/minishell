/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:03 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:12:04 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
* @file defines.h
* @brief Contains macro definitions for symbols, prefixes, builtins,
* and file names used in minishell.
*
* This header centralizes all constant values and macros for easy
* maintenance and consistency.
*/

/**
 * .-------------------------------------.
 * | ____                  _           _ |
 * |/ ___| _   _ _ __ ___ | |__   ___ | ||
 * |\___ \| | | | '_ ` _ \| '_ \ / _ \| ||
 * | ___) | |_| | | | | | | |_) | (_) | ||
 * ||____/ \__, |_| |_| |_|_.__/ \___/|_||
 * |       |___/                         |
 * '-------------------------------------'
 */

// Symbol definitions (single characters)
# define SYMBOL_PIPE            '|'
# define SYMBOL_GREATER_THAN    '>'
# define SYMBOL_LESS_THAN       '<'
# define SYMBOL_QUOTE           '\''
# define SYMBOL_QUOTE_DOUBLE    '\"'
# define SYMBOL_DOLLAR          '$'
# define SYMBOL_QUESTION_MARK   '?'
# define SYMBOL_EQUAL           '='

// Symbol definitions (strings)
# define SYMBOL_CHAR_PIPE                   "|"
# define SYMBOL_CHAR_GREATER_THAN           ">"
# define SYMBOL_CHAR_LESS_THAN              "<"
# define SYMBOL_CHAR_DOUBLE_GREATER_THAN    ">>"
# define SYMBOL_CHAR_DOUBLE_LESS_THAN       "<<"

/**
 * .------------------------------------.
 * | ____            __ _               |
 * ||  _ \ _ __ ___ / _(_)_  _____  ___ |
 * || |_) | '__/ _ \ |_| \ \/ / _ \/ __||
 * ||  __/| | |  __/  _| |>  <  __/\__ \|
 * ||_|   |_|  \___|_| |_/_/\_\___||___/|
 * '------------------------------------'
 */

// Environment variable prefixes and lengths
# define PWD_PREFIX         "PWD="
# define PWD_PREFIX_LEN     4

# define OLDPWD_PREFIX      "OLDPWD="
# define OLDPWD_PREFIX_LEN  7

# define PATH_PREFIX        "PATH="
# define PATH_PREFIX_LEN    5

# define HOME               "/home/"
# define HOME_LEN           6

# define EXPORT             "export"
# define EXPORT_LEN         6

/**
 * .---------------------------------.
 * | ____        _ _ _   _           |
 * || __ ) _   _(_) | |_(_)_ __  ___ |
 * ||  _ \| | | | | | __| | '_ \/ __||
 * || |_) | |_| | | | |_| | | | \__ \|
 * ||____/ \__,_|_|_|\__|_|_| |_|___/|
 * '---------------------------------'
 */

// Builtin command names and lengths
# define BUILTIN_ECHO           "echo"
# define BUILTIN_ECHO_LEN       5

# define BUILTIN_CD             "cd"
# define BUILTIN_CD_LEN         3

# define BUILTIN_PWD            "pwd"
# define BUILTIN_PWD_LEN        4

# define BUILTIN_EXPORT         "export"
# define BUILTIN_EXPORT_LEN     7

# define BUILTIN_UNSET          "unset"
# define BUILTIN_UNSET_LEN      6

# define BUILTIN_ENV            "env"
# define BUILTIN_ENV_LEN        4

# define BUILTIN_EXIT           "exit"
# define BUILTIN_EXIT_LEN       5

/**
 * .--------------------------------------------------.
 * | _____ _ _        _   _                           |
 * ||  ___(_) | ___  | \ | | __ _ _ __ ___   ___  ___ |
 * || |_  | | |/ _ \ |  \| |/ _` | '_ ` _ \ / _ \/ __||
 * ||  _| | | |  __/ | |\  | (_| | | | | | |  __/\__ \|
 * ||_|   |_|_|\___| |_| \_|\__,_|_| |_| |_|\___||___/|
 * '--------------------------------------------------'
 */

// History and heredoc file names
# define HISTORY_FILE           ".m&mshell_history"
# define FILENAME_HEREDOC       "build/.tmp_heredoc_file_"

#endif
