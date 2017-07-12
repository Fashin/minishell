/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:58 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 22:03:41 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFSIZE 10
# define BUILTINS "echo;cd;setenv;unsetenv;exit"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct			s_env
{
		char			*name;
		char			*value;
}						t_env;

char					**search_command(char *str);
char					**convert_env(t_list *list);
char					*get_path(t_list *list);
char					*read_standard_input(void);
char					*path_cmd(char *path, char *cmd);
void					puterror(int stop, char *msg);
void					exec_interne(char *cmd, char **params, t_list *list);
void					ft_echo(char **params);
void					ft_exit(char *cmd, char **params, t_list *list, int stop);
void					ft_cd(void);
int					resolve_command(char **cmds, t_list *list);
int					save_env(char **env, t_list **list);

#endif
