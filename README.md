TODO:
	- Executor:  
		- Commands:  
			- ft_handle_cmd  
			- ft_find_cmd  
			- ft_check_redirections  
		- Redirections  
			- ft_handle_infile  
			- ft_handle_outfile  
			- ft_handle_infile  
		- Builtins  
		- Pipeline commands  
			- ft_execute_pipeline_command  
			- ft_fork  
			- ft_check_fd_heredoc  
NORMINETTE:
	- Headers
	- Errors:
		- executor.h  
		- expander.h  
		- redirections.c  
		- handle_cmd.c
		- executor.c  
		- heredoc.c  
		- ft_exit.c  
		- ft_cd.c  
		- ft_unset.c  

FIXME:
	- $?
		- Leak on $?
	- Readline
		- when write something like ls > cat -e | ls and then arrow up. the readline stay with some trash like ls > cat -e | 

