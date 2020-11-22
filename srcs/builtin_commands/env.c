/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcustard <kcustard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:39 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/22 15:29:35 by kcustard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Функция возвращает одномерный массив со всеми переменными окружения.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, думаю, что тут не нужен exit.
*/

#include "../../header/minishell.h"

void	error_output(t_commands *cmd, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s); //

char	*ft_env(t_commands *cmd, t_data *all)
{
	//int		len;
	int		i;
	char	*string;
	char	*temp_str;

	i = 3;
	if (cmd->count_args > 0)
	{
		ft_putstr("env: '");
		ft_putstr(cmd->lst->content);
		ft_putstr("': ");
		error_output(cmd, "No such file or directory");
	}
	/*
	len = ft_strlen(all->envp[all->env_var]);
	while (--i >= 0 && --len >= 0)
		all->envp[all->env_var][len] = cmd->cmd[i];
	*сначала нужно разобраться с тем, как отображается эта строка в 
	*bash и понять, где она там находится, нужно ли вообще её менять 
	*/
	if (!(string = ft_strdup("")))
		error_output(cmd, "malloc: ft_env");
	i = 0;
	while (all->envp[i])
	{
		temp_str = string;
		if (!(string = ft_strjoin(string, all->envp[i])))
			error_output(cmd, "malloc: ft_env");
		free(temp_str);
		temp_str = string;
		if (!(string = all->envp[++i] ? ft_strjoin(string, "\n") : string))
			error_output(cmd, "malloc: ft_env");
		if (ft_strcmp(temp_str, string) != 0)
			free(temp_str);
	}
	return (string);
}
