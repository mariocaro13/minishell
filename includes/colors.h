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

# define COLOR_RESET			"\033[0m"

/**
 *  ____  _                  _            
 * / ___|| |_ __ _ _ __   __| | __ _ _ __ 
 * \___ \| __/ _` | '_ \ / _` |/ _` | '__|
 *  ___) | || (_| | | | | (_| | (_| | |   
 * |____/ \__\__,_|_| |_|\__,_|\__,_|_|   
 */

# define COLOR_BLACK   			"\033[30m"
# define COLOR_WHITE   			"\033[37m"
# define COLOR_RED     			"\033[31m"
# define COLOR_GREEN   			"\033[32m"
# define COLOR_YELLOW  			"\033[33m"
# define COLOR_BLUE    			"\033[34m"
# define COLOR_MAGENTA 			"\033[35m"
# define COLOR_CYAN    			"\033[36m"
# define COLOR_GREY    			"\033[90m"

/**
 *  ____  _           _ 
 * | __ )| | ___   __| |
 * |  _ \| |/ _ \ / _` |
 * | |_) | | (_) | (_| |
 * |____/|_|\___/ \__,_|
 */

# define COLOR_BLACK_BOLD   	"\033[1;30m"
# define COLOR_WHITE_BOLD   	"\033[1;37m"
# define COLOR_RED_BOLD     	"\033[1;31m"
# define COLOR_GREEN_BOLD   	"\033[1;32m"
# define COLOR_YELLOW_BOLD  	"\033[1;33m"
# define COLOR_BLUE_BOLD    	"\033[1;34m"
# define COLOR_MAGENTA_BOLD 	"\033[1;35m"
# define COLOR_CYAN_BOLD    	"\033[1;36m"
# define COLOR_BROWN_BOLD		"\033[1;38;130m"

/**
 *  _     _       _     _   
 * | |   (_) __ _| |__ | |_ 
 * | |   | |/ _` | '_ \| __|
 * | |___| | (_| | | | | |_ 
 * |_____|_|\__, |_| |_|\__|
 *          |___/           
 */

# define COLOR_LIGHT_RED		"\033[91m"
# define COLOR_LIGHT_GREEN		"\033[92m"
# define COLOR_LIGHT_YELLOW		"\033[93m"
# define COLOR_LIGHT_BLUE		"\033[94m"
# define COLOR_LIGHT_MAGENTA	"\033[95m"
# define COLOR_LIGHT_CYAN		"\033[96m"
# define COLOR_LIGHT_GREY		"\033[37m"
# define COLOR_LIGHT_BROWN		"\033[38;180m"

/**
 *   ____          _                  
 *  / ___|   _ ___| |_ ___  _ __ ___  
 * | |  | | | / __| __/ _ \| '_ ` _ \ 
 * | |__| |_| \__ \ || (_) | | | | | |
 *  \____\__,_|___/\__\___/|_| |_| |_|
 */

# define COLOR_BROWN			"\033[38;130m"

#endif
