#ifndef INIT_H
# define INIT_H

int		ft_init_shell_dirs(t_shell_data *shell_data);
void	ft_init_shell_data(t_shell_data *shell_data);
void	ft_init_global_shell_state(t_shell_data *shell_data);
int		ft_init_shell_envp(t_shell_data *shell_data, char **envp);
int		ft_init_env_paths(t_shell_data *shell_data);
int		ft_set_default_paths(t_shell_data *shell_data);
void	ft_init_signals(void);
int		ft_init_shell(t_shell_data *shell_data, char **envp);

#endif
