#include "minishell.h"

char    *ft_strnrcpy(char *str, char *temp, int c)
{
    int i;
    char tmp;
    temp = malloc(sizeof(char) * strlen(str) - c);
    if (!temp)
        return (NULL);
    i = 0;
    while(str[c] != '\0')
    { 
        
        tmp = str[c];
        temp[i] = tmp;
        i++;
        c++;
    }
    return (temp);
}

char**  get_arg(char *cmd, t_token *token)
{
    int i;
    char *temp;

    i = token->start_arg;
    temp = (ft_strnrcpy(cmd,temp,i));
    token->arg = ft_split(temp, ' ');
    i = 0;
    while (token->arg[i] != 0)
    {
        printf("je suis l'argument n%d = %s\n", i , token->arg[i]);
        i++;
    }
    return (token->arg);
  
}

char*    get_cmdr(char *cmd, t_token *token)
{
    int i;
    int c;
    int k;
    char *str;

    i = 0;
    c = 0;
    while (cmd[i] != '\0')
    {
        while (cmd[i] == ' ')
            i++;
        if (cmd[i] != '<' && cmd[i] != '>' && cmd[i] != '-' && (cmd[i] < 'a' || cmd[i] > 'z'))
            return (NULL);
        k = i;
        while (cmd[i + c] != '\0' && cmd[i + c] != ' ' || (cmd[i + c] >= 'a' && cmd[i + c] <= 'z'))
            c++;
        break ;
    }
    i = 0;
    str = malloc(sizeof(char) * c - 1);
    while (i <= c - 1)
        str[i++] = cmd[k++];
    token->start_arg = k;
    return (str);
    
}

int init_struct(char **cmd, t_token *token)
{
    int i;
    int k;

    i = 0;
    while (cmd[i] != 0)
        i++;
    k = i;
    token = malloc(sizeof(t_token) * i);
    if (!token)
        return (0);
    i = 0;
    while (cmd[i] != 0)
    {
        token[i].cmdr = get_cmdr(cmd[i], &token[i]);
        token[i].arg = get_arg(cmd[i], &token[i]);
        i++;
    }
    i = 0;
    while (i < k)
    {
        printf("%s\n", token[i].cmdr);    
        i++;
    }
    return (1);
}

int token(char **cmd, t_token *token)
{
    init_struct(cmd, token);
    return (1);
}