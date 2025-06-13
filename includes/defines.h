#ifndef DEFINES_H
# define DEFINES_H

/**
*  ____                  _           _     
* / ___| _   _ _ __ ___ | |__   ___ | |___ 
* \___ \| | | | '_ ` _ \| '_ \ / _ \| / __|
*  ___) | |_| | | | | | | |_) | (_) | \__ \
* |____/ \__, |_| |_| |_|_.__/ \___/|_|___/
*        |___/                             
*/

// Int type
# define SYMBOL_PIPE			'|'
# define SYMBOL_GREATER_THAN	'>'
# define SYMBOL_LESS_THAN		'<'
# define SYMBOL_QUOTE			'\''
# define SYMBOL_QUOTE_DOUBLE	'\"'
# define SYMBOL_DOLLAR			'$'
# define SYMBOL_QUESTION_MARK	'?'
# define SYMBOL_EQUAL			'='
// Char[2] type
# define SYMBOL_CHAR_PIPE					"|"
# define SYMBOL_CHAR_GREATER_THAN			">"
# define SYMBOL_CHAR_LESS_THAN				"<"
# define SYMBOL_CHAR_DOUBLE_GREATER_THAN	">>"
# define SYMBOL_CHAR_DOUBLE_LESS_THAN		"<<"

/**
*  ____            __ _               
* |  _ \ _ __ ___ / _(_)_  _____  ___ 
* | |_) | '__/ _ \ |_| \ \/ / _ \/ __|
* |  __/| | |  __/  _| |>  <  __/\__ \
* |_|   |_|  \___|_| |_/_/\_\___||___/
*/

# define PWD_PREFIX "PWD="
# define PWD_PREFIX_LEN 4

# define OLDPWD_PREFIX "OLDPWD="
# define OLDPWD_PREFIX_LEN 7

# define PATH_PREFIX "PATH="
# define PATH_PREFIX_LEN 5

# define HOME_PREFIX "HOME="

# define EXPORT "export"
# define EXPORT_LEN 6

/**
*  ____        _ _ _   _           
* | __ ) _   _(_) | |_(_)_ __  ___ 
* |  _ \| | | | | | __| | '_ \/ __|
* | |_) | |_| | | | |_| | | | \__ \
* |____/ \__,_|_|_|\__|_|_| |_|___/
*/

# define BUILTIN_ECHO		"echo"
# define BUILTIN_ECHO_LEN	5

# define BUILTIN_CD			"cd"
# define BUILTIN_CD_LEN		3

# define BUILTIN_PWD		"pwd"
# define BUILTIN_PWD_LEN	4

# define BUILTIN_EXPORT		"export"
# define BUILTIN_EXPORT_LEN	7

# define BUILTIN_UNSET		"unset"
# define BUILTIN_UNSET_LEN	6

# define BUILTIN_ENV		"env"
# define BUILTIN_ENV_LEN	4

# define BUILTIN_EXIT		"exit"
# define BUILTIN_EXIT_LEN	5

/**
*  _____ ___ _     _____ ____  
* |  ___|_ _| |   | ____/ ___| 
* | |_   | || |   |  _| \___ \ 
* |  _|  | || |___| |___ ___) |
* |_|   |___|_____|_____|____/ 
*/

# define HISTORY_FILE		".minishell_history"
# define FILENAME_HEREDOC	"build/.tmp_heredoc_file_"

#endif
