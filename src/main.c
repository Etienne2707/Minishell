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

int	Syntax_Error(char *str, t_token *token)
{
	int	i;
	char **cmd;

	i = 0;
	cmd = ft_split(str, '|');
	
	if ((no_authorize(str)) == -1)
		return (-1);
	init_struct(cmd, token);
	
	
}
int	check_str(char *str, t_token *token)
{

    if ((Syntax_Error(str, token)) == -1)
	{
		write(1, "Syntax Error\n", 13);
		return (-1);
	}
}

int	main(int ac, char **argv, char **envp)
{
	t_token *token;
	int i;
	char *str;

	while (-1)
	{
		str = readline("Minishell > ");
		check_str(str, token);
		if (strcmp(str, "exit") == 0)
			return (0);
	}
}