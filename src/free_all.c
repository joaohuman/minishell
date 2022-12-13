/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:38:52 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/10 03:18:11 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst_env(t_list **lst_env)
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst_env;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst_env = NULL;
}

void	free_all(t_list **lst_env, char *cmd)
{
	rl_clear_history();
	free_lst_env(lst_env);
	free(cmd);
}
