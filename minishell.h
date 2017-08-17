/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:58 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 20:14:51 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFSIZE 10
# define BUFFPATH 1024
# define BUILTINS "env;echo;cd;setenv;unsetenv;exit;set-prompt-color"
# define W_ENV "cb_zsh : you don't have set environnement\n"
# define NF_CMD "cb_zsh : command not found : "
# define NF_ENV "cb_zsh : can't find home directory"
# define NF_COLOR "cb_zsh : can't find this color\n"
# define NF_ACCESS "cb_zsh : can't access to this executable"
# define NF_FILE "cb_zsh : no such file or directory "
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>

typedef struct			s_env
{
		char			*name;
		char			*value;
}						t_env;

t_list					*list_update(char *name, char *new_value, t_list *list);
t_list					*ft_cd(char **params, t_list **list);
t_list					*exec_interne(char **params, t_list *list);
t_list					*resolve_command(char **cmds, t_list *list, int clean);
t_list					*env(char **params, t_list **list);
t_list					*set_env(char **params, t_list *list);
t_list					*unset_env(char **params, t_list *list);
t_list					*search_command(char *cmd, t_list *list);
t_list					*set_params(char *str, int interne, t_list *list);
t_list					*ft_prompt(t_list *list);
t_list					*set_prompt(char **av, t_list *list);
char					**convert_env(t_list *list);
char					*get_value(t_list *list, char *name);
char					*path_cmd(char *path, char *cmd);
char					*get_color(char *name, char **buff);
char					*check_pers_cmd(char *str, int *intern);
char					*convert_special_char(char *str, t_list *list);
void					puterror(int stop, char *msg);
void					ft_echo(char **params);
void					ft_exit(char **params, t_list *list, int stop);
void					free_tab(char ***params);
void					save_cmd(char **cmds, t_list *list);
void					free_env(void *content, size_t size);
void					list_remove(t_list **list, char *name);
void					print_env(t_list *list);
int						save_env(char **env, t_list **list);

#endif
