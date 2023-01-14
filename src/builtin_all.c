/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/14 01:11:37 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_all(char *cmd, t_list **envp, int status)
{
	if (ft_strncmp(cmd, "export", 6) == 0)
		status = builtin_export((cmd + 7), envp);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		status = builtin_unset((cmd + 6), envp);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		status = builtin_env(*envp);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		status = builtin_exit();
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		status = builtin_pwd();
	else if (ft_strncmp(cmd, "echo", 4) == 0)
		builtin_echo(cmd + 5);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		status = builtin_cd(cmd + 3, envp);
	else
		status = builtin_other(cmd, envp);
	return (status);
}
