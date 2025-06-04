#include "minishell.h"

int	(*ft_get_builtin_function(char *str))(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	static void	*builtins[7][2] = {
	{"echo", mini_echo},
	{"cd", ft_cd},
	{"pwd", mini_pwd},
	{"export", ft_export},
	{"unset", ft_unset},
	{"env", mini_env},
	{"exit", ft_exit}
	};
	int			index;

	index = 0;
	while (index < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[index][0], str, ft_strlen((builtins[index][0]))))
				return (builtins[index][1]);
		}
		index++;
	}
	return (NULL);
}
