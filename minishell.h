/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:58 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 17:45:51 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFSIZE 10
# define BUFFPATH 1024
# define BUILTINS "env;echo;cd;setenv;unsetenv;exit;set-prompt-color"
# define NF_CMD "cb_zsh : command not found : "
# define NF_ENV "cb_zsh : can't find home directory"
# define NF_COLOR "cb_zsh : can't find this color\n"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define LIGHT_GRAY "\e[37m"
# define DARK_GRAY "\e[90m"
# define LIGHT_RED "\e[91m"
# define LIGHT_GREEN "\e[92m"
# define LIGHT_YELLOW "\e[93m"
# define LIGHT_BLUE "\e[94m"
# define LIGHT_MAGENTA "\e[95m"
# define LIGHT_CYAN "\e[96m"
# define WHITE "\e[97m"
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
char					*path_cmd(char *path, char *cmd);
char					*is_color(char *str);
void					puterror(int stop, char *msg);
void					ft_echo(char **params);
void					ft_exit(char **params, t_list *list, int stop);
void					free_lst(t_list *list);
void					free_tab(char **params);
void					set_prompt(char **av);
void					set_params(char *str, int interne);
void					ft_prompt(void);
int						save_env(char **env, t_list **list);

#endif
