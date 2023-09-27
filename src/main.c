#include "minishell.h"

/*int	Syntax_Error(char *str, char *check)
{
	int	i;

	i = 0;
	if ((no_authorize(str)) == -1)
		return (-1);
	
    if (check_start_end(str,check) == -1)
        return (-1);
	if (only_special(str) == -1)
		return (-1);
	
	while (str[i] != '\0')
	{
        if (str[i] == '|' && (have_digit(str, i + 1) == -1))
                return (-1);
        i++;
	}
    return (0);
}*/
char	*change_value(char *value, char *str, char *swap, int c)
{
	char	*new;
	int i;
	int k;

	i = 0;
	k = 0;
	new = malloc(sizeof(char) * ft_strlen(swap) + (ft_strlen(str) - ft_strlen(value) + 1));
	if (!new)
		return (NULL);
	new = ft_strlcpy(new,str,c);
	new = ft_strjoin(new,swap);
	new = ft_strnjoin(new, str, c + ft_strlen(value));
	return (new);
}


char	*get_value(char *env, char *str)
{
	int i;
	int c;
	char	*value;

	i = ft_strlen(str) + 1;
	c = 0;
	if(ft_compare(str, env, ft_strlen(str)) != 0)
		return (NULL);
	value = malloc(sizeof(char) * ft_strlen(env) - ft_strlen(str) + 2);
	while (env[i] != '\0')
	{
		value[c] = env[i];
		i++;
		c++;
	}
	return (value);
}
	char	*swap_value(char *value, char **envp)
	{
		int i;
		char *str;

		i = 0;
		while (envp[i] != NULL)
		{
			if ((str = get_value(envp[i], value)) != NULL)
				return (str);
			
			i++;
		}
		return (NULL);
	}


char*	get_dollars(char *str, int pos, char **envp)
{
	int i;
	int c;
	char *value;
	char *new;

	i = pos + 1;
	while (str[pos] != ' ' && str[pos] != '}' && str[pos] != '_' && (str[pos] < '0' || str[pos] > '9') && str[pos] != '\0')
		pos++;
	value = malloc(sizeof(char) * pos - i + 1);
	if (!value)
		return (NULL);
	c = 0;
	while (i < pos)
	{
		value[c] = str[i];
		i++;
		c++;
	}
	c = i - c;
	return (change_value(value, str, swap_value(value, envp), c));
}

char*	checkdollars(char *str, char **envp)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '$')
		{
			str = get_dollars(str, i, envp);
		}
		i++;
	}
	return (str);
	
}

int	check_pipe(char **cmd, char *str)
{
	int i;
	int k;
	int c;

	i = 0;
	c = 0;
	if (check_start_end(str) == -1)
		return (-1);
	while(cmd[i] != 0)
	{
		k = 0;
		c = 0;
		while (cmd[i][k] != '\0')
		{
			if (cmd[i][k] != ' ')
				c++;
			k++;
			
		}
		if (c == 0)
				return (-1);
		i++;
	}
	return (1);
	
}

int	Syntax_Error(char *str, t_token *token, char **envp)
{
	int	i;
	char **cmd;

	i = 0;
	str = checkdollars(str, envp);
	cmd = ft_split(str, '|');	
	if ((check_pipe(cmd, str)) == -1)
		return (-1);
	if ((no_authorize(str)) == -1)
		return (-1);
	init_struct(cmd, token);
	return (1);
	
}
int	check_str(char *str, t_token *token, char **envp)
{

    if ((Syntax_Error(str, token, envp)) == -1)
	{
		write(1, "Syntax Error\n", 13);
		return (-1);
	}
	return (1);
}

int	main(int ac, char **argv, char **envp)
{
	t_token *token;
	(void)ac;
	(void)argv;
	int i;
	char *str;

	token = NULL;
	str = NULL;
	str = readline("Minishell > ");
	while (-1)
	{
		
		check_str(str, token, envp);
		if (strcmp(str, "exit") == 0)
			return (0);
		str = readline("Minishell > ");
	}
	return (1);
}