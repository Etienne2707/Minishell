#include "minishell.h"

char*    get_cmdr(char *cmd)
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
        if (cmd[i] != '<' && cmd[i] != '>' && (cmd[i] < 'a' || cmd[i] > 'z'))
            return (NULL);
        k = i;
        while (cmd[i + c] != '\0' && cmd[i + c] != ' ' || (cmd[i + c] >= 'a' && cmd[i + c] <= 'z'))
            c++;
        break ;
    }
    i = 0;
    str = malloc(sizeof(char) * c);
    while (i <= c)
        str[i++] = cmd[k++];

    
    return (str);
    
}

int init_struct(char **cmd, t_token *token)
{
    int i;

    i = 0;
    while (cmd[i] != 0)
        i++;
    token = malloc(sizeof(t_token) * i);
    if (!token)
        return (0);
    i = 0;
    while (cmd[i] != 0)
    {
        token->cmdr = get_cmdr(cmd[i]);
        printf("%s\n", token->cmdr);
        i++;
    }
    return (1);
}

int token(char **cmd, t_token *token)
{
    init_struct(cmd, token);
    return (1);
}