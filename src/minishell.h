/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:48:24 by educlos           #+#    #+#             */
/*   Updated: 2023/09/26 15:27:19 by educlos          ###   ########.fr       */
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

#endif
