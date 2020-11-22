# include "../../header/minishell.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while ((ps1[i] != '\0' || ps2[i] != '\0') && i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char		*ft_strndup(const char *src, size_t n)
{
	char	*new_array;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!(new_array = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i] && size != n)
	{
		new_array[i] = src[i];
		i++;
		size++;
	}
	new_array[i] = '\0';
	return (new_array);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	size_d;

	n = size;
	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && --n != 0)
		{
			dest[i] = src[i];
			i++;
		}
		if (src[i] == '\0')
			dest[i] = '\0';
	}
	if (n == 0 && size != 0)
		dest[i] = '\0';
	size_d = ft_strlen(src);
	return (size_d);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dest[i] != '\0')
		++i;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*nstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(nstr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_strlcpy(nstr, s1, lens1 + 1);
	ft_strlcat(nstr, s2, lens1 + lens2 + 1);
	return (nstr);
}

char		*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src);
	if (!(p = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

void		ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
	}
}

void	error_output(t_commands *cmd, char *str)
{
	free(cmd);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	exit(0);
}

static char	**copy_double_array(char **origin, t_commands *cmd)
{
	char	**duplicate;
	int		num_of_str;
	int		index;

	num_of_str = 0;
	index = 0;
	while (origin[num_of_str])
		num_of_str++;
	if (!(duplicate = (char **)malloc(sizeof(char *) * (num_of_str + 1))))
		error_output(cmd, MALLOC_10);
	duplicate[num_of_str] = NULL;
	while (index < num_of_str)
	{
		if (!(duplicate[index] = ft_strdup(origin[index])))
			error_output(cmd, MALLOC_10);
		index++;
	}
	return (duplicate);
}

static void	data_filling(t_data **all)
{
	int		index;

	index = 0;
	while ((*all)->envp[index])
	{
		if (ft_strncmp((*all)->envp[index], "HOME=", 5) == 0)
			(*all)->home_dir = index;
		if (ft_strncmp((*all)->envp[index], "PWD=", 4) == 0)
			(*all)->current_pwd = index;
		if (ft_strncmp((*all)->envp[index], "OLDPWD=", 7) == 0)
			(*all)->old_pwd = index;
		if (ft_strncmp((*all)->envp[index], "_=", 2) == 0)
			(*all)->env_var = index;
		index++;
	}
	(*all)->count_str = index;
}

void	create_env_v(t_data **all, char **envp_baze, t_commands *cmd)
{
	if (!((*all) = (t_data *)malloc(sizeof(t_data))))
		error_output(cmd, MALLOC_9);
	(*all)->envp = NULL;
	(*all)->home_dir = -1;
	(*all)->current_pwd = -1;
	(*all)->old_pwd = -1;
	(*all)->env_var = -1;
	(*all)->envp = copy_double_array(envp_baze, cmd);
	(*all)->count_str = -1;
	(*all)->error_string = NULL;
	data_filling(all);
}

void	create_cmd(t_commands **cmd, char **argv, int argc)
{
	t_list	*lst;
	t_list	*temp_lst;
	int		index;

	index = 0;
	if (!((*cmd) = (t_commands *)malloc(sizeof(t_commands))))
		error_output(*cmd, MALLOC_11); //нужен маллок 13
	(*cmd)->cmd = NULL;
	(*cmd)->num_cmd = 0;
	(*cmd)->cmd_dir = NULL;
	(*cmd)->count_args = argc;
	(*cmd)->type_redir = 0;
	(*cmd)->invalid = 0;
	if (argc > 0)
	{
		if (!((*cmd)->lst = (t_list *)malloc(sizeof(t_list))))
				error_output(*cmd, MALLOC_11); //нужен маллок 13
		(*cmd)->lst->next = NULL;
		(*cmd)->lst->content = argv[index];
		lst = (*cmd)->lst;
		index++;	
		while (index < argc)
		{
			if (!(temp_lst = (t_list *)malloc(sizeof(t_list))))
				error_output(*cmd, MALLOC_11); //нужен маллок 13
			temp_lst->next = NULL;
			temp_lst->content = argv[index];
			lst->next = temp_lst;
			lst = lst->next;
			index++;
		}
		lst->next = NULL;
	}
	(*cmd)->redir = NULL;
	(*cmd)->pipe = NULL;
	(*cmd)->next = NULL;
}

char	*ft_env(t_commands *cmd, t_data *all);
void	ft_cd(t_commands **cmd, t_data *all);
char	*ft_echo(t_commands *cmd);
void	ft_export(t_commands **cmd, t_data **all);
char	*ft_pwd(t_commands *cmd, t_data *all);

#include <stdio.h>

int    			main(int argc, char **argv, char **envp)
{
    t_commands	*cmd;
	t_data		*all;
	char		**copy_args;
	
	(void)argv;
	
// создаем структуру для cd 	
	argc = 3;
	if (!(copy_args = (char **)malloc(sizeof(char *) * argc)))
		return (0);
	int index = 0;
	while (index < argc)
	{
		if (!(copy_args[index] = ft_strdup("/home/venus/Desktop/Nastya")))
			return (0);
		index++;
	}
////////////////////////////

	all = NULL;
	cmd = NULL;
	create_env_v(&all, envp, cmd);
	create_cmd(&cmd, copy_args, argc);

// check cd	
	/*
	char s[100];
	printf("%s\n", getcwd(s, 100)); 
	ft_cd(&cmd, all);
	printf("%s\n", getcwd(s, 100));
	printf("%s\n", all->envp[all->old_pwd]);
	printf("%s\n", all->envp[all->current_pwd]);
	*/
/////////////

// check pwd
	/*
	printf("%s\n", ft_pwd(cmd, all));
	*/
/////////////

// check echo
	/*
	printf("%s", ft_echo(cmd));
	*/
/////////////	

// check env
	/*
	printf("%s\n", ft_env(cmd, all));
	*/
/////////////

// check export
	
	ft_export(&cmd, &all);
	cmd->count_args = 0;
	printf("%s\n", ft_env(cmd, all));
	
/////////////

	return (0);
}
