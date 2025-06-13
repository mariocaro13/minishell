## TODO:

- ### Executor:  
	- [x] Commands:  
        
	- [x] Redirections  
        
	- [x] Builtins
		- [x] ft_cd		✅
		- [x] ft_echo	✅
		- [x] ft_env	✅
		- [x] ft_exit	✅
		- [x] ft_export	✅
		- [x] ft_pwd	✅
		- [x] ft_unset	✅
       
- ### SIGNALS:
	- [x] Crtl + \ 
	- [x] Crtl + C 
	- [x] Crtl + D 

	
## NORMINETTE:

- [ ] Headers

## FIXME:

> [!CAUTION]
> - [ ]  ft_exit:
> cat | exit -> leak

> [!WARNING]
> echo 
>   - [ ] no imprime el $ (posiblemente culpa del parser)
>   - [ ] no imprime las comillas dentro de comillas (posiblemente culpa del parser). 

> [!WARNING]
> echo "'" o echo '"' no imprime las comillas, las comillas dentro de comillas se ignoran, esto creo que es bonus
> Echarle un ojo

> [!IMPORTANT]
> - [ ]  Readline:
> 1. Write something like: ⬇️  
> `ls > out| cat | cat -e`
> 2. Then arrow up. Readline keeps some trash like ⬇️  
> `ls > out |`

