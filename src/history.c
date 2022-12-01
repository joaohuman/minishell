/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/30 22:05:26 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_list(t_list *lst)
{
    while (lst->next)
    {
        printf("%s\n", lst->content);
        lst = lst->next;
    }
    printf("%s\n", lst->content);
}

int	ft_add_history(char *cmd)
{
    static t_list *history;

    if (history == NULL)
        history = ft_lstnew(cmd);
    else
        ft_lstadd_back(&history, ft_lstnew(cmd));
    //print_list(history);
    return (0);
}
