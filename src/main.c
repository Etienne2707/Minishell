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

char	*get_value(char *env, char *str)
{
	size_t i;
	size_t c;
	char	*value;

	i = strlen(str) + 1;
	c = 0;
	printf("%d\n", strlen(str));
	if(strncmp(env, str, strlen(str) + 1 != 0))
		return (NULL);
	printf("%d\n", strlen(env) - strlen(str) - 1);
	value = malloc(sizeof(char) * strlen(env) - strlen(str) + 1);
	while (env[i] != '\0')
	{
		value[c] = env[i];
		i++;
		c++;
	}
	printf("%s\n", value);
	return (value);
}

void	switch_dollars(char *str, char *value, char **envp)
{
	int i;
	char *dol;

	i = 0;
	while(envp[i] != 0)
	{
		dol = get_value(envp[i], value);
		i++;
	}
	return ;

}

char*	get_dollars(char *str, int pos, char **envp)
{
	int i;
	int c;
	char *value;

	i = pos + 1;
	while (str[pos] != '}' && str[pos] != '_' && (str[pos] < '0' || str[pos] > '9'))
		pos++;
	value = malloc(sizeof(char) * pos - i);
	if (!value)
		return (NULL);
	c = 0;
	while (i < pos)
	{
		value[c] = str[i];
		i++;
		c++;
	}
	c = c - i;
	printf("%s\n", value);
	return (value);
}

char	*checkdollars(char *str, char **envp)
{
	int i;
	char *value;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '$')
		{
			value = get_dollars(str, i, envp);
			switch_dollars(str,value,envp);
		}
		i++;
	}
	return (NULL);
	
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
	cmd = ft_split(str, '|');
	checkdollars(str, envp);
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
	int i;
	char *str;

	while (-1)
	{
		str = readline("Minishell > ");
		check_str(str, token, envp);
		if (strcmp(str, "exit") == 0)
			return (0);
	}
	return (1);
}