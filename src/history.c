/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/01 21:08:48 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_history(char *cmd)
{
	static t_list	*history;

	if (history == NULL)
		history = ft_lstnew(cmd);
	else
		ft_lstadd_back(&history, ft_lstnew(cmd));
	return (0);
}
