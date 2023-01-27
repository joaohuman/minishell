/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/27 01:13:36 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	char	**cmd_tkn;
	t_list	*lst_env;
	// int		status;
	char	buffer[2048];

	//fazer funcao que inicializa funcoes
	cmd_tkn = NULL;
	cmd = NULL;
	lst_env = NULL;
	// status = 1;
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	lst_env = env_to_lst(envp);
	if (lst_env == NULL)
		printf("erro");
	define_signals();
	// while (status)
	while (1)
	{
		cmd = readline(ft_strjoin(getcwd(buffer, 2048), "|--HELL-->"));
		if (cmd == NULL)
			// status = 0;
			break ;
		else
		{
			ft_add_history(cmd);
			// cmd_tkn = tokenizer(cmd, cmd_tkn);
			// status = builtin_all(cmd, &lst_env, status, cmd_tkn);
			builtin_pipe_to_all(cmd, &lst_env);
		}
	}
	free_all(&lst_env, cmd, cmd_tkn);
}
