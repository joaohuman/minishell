/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/31 23:48:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	t_list	*lst_env;
	char	buffer[2048];

	cmd = NULL;
	lst_env = env_to_lst(envp);
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	if (lst_env == NULL)
		printf("erro");
	define_signals();
	while (1)
	{
		cmd = readline(ft_strjoin(getcwd(buffer, 2048), "|--HELL-->"));
		if (cmd == NULL)
			break ;
		else if (ft_strlen(cmd) > 0)
		{
			ft_add_history(cmd);
			builtin_pipe_to_all(cmd, &lst_env);
		}
	}
	free_part(&lst_env, cmd);
}
//quando da enter buga o readline