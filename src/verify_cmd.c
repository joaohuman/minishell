/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:17:17 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/17 01:52:10 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initial_verify_cmd(char **cmd)
{
	if (!ft_strncmp(cmd[0], ".", 1))
		return (-1);
	if (!ft_strncmp(cmd[0], "./", 2))
		return (-1);
	if (!ft_strncmp(cmd[0], "/", 1))
		return (-1);
	if (!ft_strncmp(cmd[0], "|", 1))
		return (-1);
	return (0);
}

int	verify_cmd(char **cmd)
{
	if (have_two_quotes(*cmd) == -1)
		return (-1);
	if (ft_strlen(cmd[0]) < 3 && count_vector(cmd) == 1)
		if (initial_verify_cmd(cmd) == -1)
			return (-1);
	while (*cmd)
	{
		if (!ft_strncmp(*cmd, "||", 2))
			return (-1);
		if (!ft_strncmp(*cmd, "\\", 2))
			return (-1);
		if (!ft_strncmp(*cmd, ";", 1))
			return (-1);
		if (!ft_strncmp(*cmd, ">>>", 3))
			return (-1);
		if (!ft_strncmp(*cmd, "<<<", 3))
			return (-1);
		cmd++;
	}
	return (0);
}