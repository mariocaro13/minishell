## TODO:

- ### Executor:  
	- [ ] Commands:  
		- [ ] ft_handle_cmd  
		- [ ] ft_find_cmd  
		- [ ] ft_check_redirections
        
	-  [ ] Redirections  
		- [ ] ft_handle_infile  
		- [ ] ft_handle_outfile  
		- [ ] ft_handle_infile
        
	- [ ] Builtins
       
	- [ ] Pipeline commands  
		- [ ] ft_execute_pipeline_command  
		- [ ] ft_fork  
		- [ ] ft_check_fd_heredoc
 
## NORMINETTE:

- [ ] Headers

- [ ] Errors:
	- [ ] executor.h
	- [ ] expander.h
	- [ ] redirections.c  
	- [ ] handle_cmd.c
	- [ ] executor.c  
	- [ ] heredoc.c
	- [ ] ft_exit.c  
	- [ ] ft_cd.c  
	- [ ] ft_unset.c  

## FIXME:
> [!CAUTION]
> - [ ]  $?
>	- Leak on $?

> [!CAUTION]
> - [ ]  Readline:
> 1. Write something like: ⬇️  
> `ls > out| cat | cat -e`
> 2. Then arrow up. Readline keeps some trash like ⬇️  
> `ls > out |`

