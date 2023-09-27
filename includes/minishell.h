/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:48:24 by educlos           #+#    #+#             */
/*   Updated: 2023/09/27 18:11:35 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

typedef struct s_token {
    char *cmdr;
    char **arg;
    int   start_arg;
}              t_token;


int	main(int ac, char **argv, char **envp);
int	have_digit(char *str, int i);
int check_start_end(char *str);
int only_special(char *str);
int no_authorize(char *str);
char	**ft_split(const char *s, char c);
int init_struct(char **cmd, t_token *token);
int	ft_strlen(char *str);
int ft_compare(char *str, char *str2, int size);
char*	ft_strlcpy(char *dest, char *src, unsigned int size);
char *ft_strjoin(char  *s1, char  *s2);
char *ft_strnjoin(char  *s1, char  *s2, int c);


#endif
