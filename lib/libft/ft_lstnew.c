/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:59:25 by aminoru-          #+#    #+#             */
/*   Updated: 2022/11/30 21:43:57 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*obj;

	obj = malloc(sizeof(t_list));
	if (obj == NULL)
		return (0);
	obj->content = content;
	obj->next = NULL;
	return (obj);
}
