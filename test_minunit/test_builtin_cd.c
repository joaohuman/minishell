/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:48:28 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/13 02:47:01 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_cd(void)
{
	t_list	*lst1 = ft_lstnew(ft_strjoin("HOME=",getenv("HOME")));
	char	*test;
	char	*espec = getenv("HOME");
	char	buffer[2048];
	
	// # Act
	builtin_cd("~", &lst1);
	test = getcwd(buffer, 2048);
	// # Assert
	mu_assert("ERROR: builtin_cd() flag ~ ", !strcmp(test, espec));
	free(lst1);
	return (0);
}
