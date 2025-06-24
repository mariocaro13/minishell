/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:58 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:11:59 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/**
 * @file colors.h
 * @brief ANSI color code macros for terminal output formatting in minishell.
 *
 * This header defines macros for standard, bold, and light color codes,
 * allowing colored and styled output in the shell.
 */

/**
 *  ____                _   
 * |  _ \ ___  ___  ___| |_ 
 * | |_) / _ \/ __|/ _ \ __|
 * |  _ <  __/\__ \  __/ |_ 
 * |_| \_\___||___/\___|\__|
 */

# define COLOR_RESET			"\001\033[0m\002"

/**
 *  ____  _                  _            
 * / ___|| |_ __ _ _ __   __| | __ _ _ __ 
 * \___ \| __/ _` | '_ \ / _` |/ _` | '__|
 *  ___) | || (_| | | | | (_| | (_| | |   
 * |____/ \__\__,_|_| |_|\__,_|\__,_|_|   
 */

# define COLOR_BLACK   			"\001\033[30m\002"
# define COLOR_WHITE   			"\001\033[37m\002"
# define COLOR_RED     			"\001\033[31m\002"
# define COLOR_GREEN   			"\001\033[32m\002"
# define COLOR_YELLOW  			"\001\033[33m\002"
# define COLOR_BLUE    			"\001\033[34m\002"
# define COLOR_MAGENTA 			"\001\033[35m\002"
# define COLOR_CYAN    			"\001\033[36m\002"
# define COLOR_GREY    			"\001\033[90m\002"

/**
 *  ____  _           _ 
 * | __ )| | ___   __| |
 * |  _ \| |/ _ \ / _` |
 * | |_) | | (_) | (_| |
 * |____/|_|\___/ \__,_|
 */

# define COLOR_BLACK_BOLD   	"\001\033[1;30m\002"
# define COLOR_WHITE_BOLD   	"\001\033[1;37m\002"
# define COLOR_RED_BOLD     	"\001\033[1;31m\002"
# define COLOR_GREEN_BOLD   	"\001\033[1;32m\002"
# define COLOR_YELLOW_BOLD  	"\001\033[1;33m\002"
# define COLOR_BLUE_BOLD    	"\001\033[1;34m\002"
# define COLOR_MAGENTA_BOLD 	"\001\033[1;35m\002"
# define COLOR_CYAN_BOLD    	"\001\033[1;36m\002"
# define COLOR_BROWN_BOLD		"\001\033[1;38;130m\002"

/**
 *  _     _       _     _   
 * | |   (_) __ _| |__ | |_ 
 * | |   | |/ _` | '_ \| __|
 * | |___| | (_| | | | | |_ 
 * |_____|_|\__, |_| |_|\__|
 *          |___/           
 */

# define COLOR_LIGHT_RED		"\001\033[91m\002"
# define COLOR_LIGHT_GREEN		"\001\033[92m\002"
# define COLOR_LIGHT_YELLOW		"\001\033[93m\002"
# define COLOR_LIGHT_BLUE		"\001\033[94m\002"
# define COLOR_LIGHT_MAGENTA	"\001\033[95m\002"
# define COLOR_LIGHT_CYAN		"\001\033[96m\002"
# define COLOR_LIGHT_GREY		"\001\033[37m\002"
# define COLOR_LIGHT_BROWN		"\001\033[38;180m\002"

/**
 *   ____          _                  
 *  / ___|   _ ___| |_ ___  _ __ ___  
 * | |  | | | / __| __/ _ \| '_ ` _ \ 
 * | |__| |_| \__ \ || (_) | | | | | |
 *  \____\__,_|___/\__\___/|_| |_| |_|
 */

# define COLOR_BROWN			"\001\033[38;130m\002"

#endif
