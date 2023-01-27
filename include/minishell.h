/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/27 01:10:02 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// lib of 42 projects
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"

// lib of readline
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

t_list	*env_to_lst(char *envp[]);
void	print_list(t_list *lst);
void	define_signals(void);
void	sig_handler(int signal);
void	free_all(t_list **lst_env, char *cmd, char **cmd_tkn);
void	free_tkn(char **cmd_tkn);
void	ft_add_history(char *cmd);
void	builtin_exit(void);
int		builtin_env(t_list *lst);
int		builtin_export(char *cmd, t_list **envp);
int		builtin_unset(char *cmd, t_list **envp);
int		builtin_all(char *cmd, t_list **envp, char **cmd_tkn);
int		builtin_pwd(void);
int		builtin_cd(char *cmd, t_list **envp);
void	builtin_echo(char **cmd_tkn, t_list **envp);
char	*take_value_of_env(char *cmd, t_list **envp);
char	**tokenizer(char *cmd, char **cmd_tkn);
int		change_value_of_env(char *cmd, char *value, t_list **envp);
int		builtin_other(char *cmd, t_list **envp);
int		ft_ispipe(char *cmd);
int		builtin_pipe_to_all(char *cmd, t_list **envp);

#endif