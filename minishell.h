/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:58 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/19 23:25:00 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFSIZE 10
# define BUFFPATH 1024
# define BUILTINS "env;echo;cd;setenv;unsetenv;exit"
# define NF_CMD "cb_zsh : command not found : "
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

t_list					*list_remove(t_list *list, char *name);
t_list					*list_update(char *name, char *new_value, t_list *list);
t_list					*ft_cd(char **params, t_list **list);
t_list					*exec_interne(char **params, t_list *list);
t_list					*resolve_command(char **cmds, t_list *list);
t_list					*env(char **params, t_list **list);
t_list					*set_env(char **params, t_list *list);
t_list					*unset_env(char **params, t_list *list);
char					**search_command(char *str);
char					**convert_env(t_list *list);
char					*get_value(t_list *list, char *name);
char					*read_standard_input(void);
char					*path_cmd(char *path, char *cmd);
void					puterror(int stop, char *msg);
void					ft_echo(char **params);
void					ft_exit(char **params, t_list *list, int stop);
void					free_lst(t_list *list);
int						save_env(char **env, t_list **list);

#endif
