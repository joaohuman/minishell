/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/27 02:58:46 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	char	**cmd_tkn;
	t_list	*lst_env;
	int		status;

	//fazer funcao que inicializa funcoes
	cmd_tkn = NULL;
	cmd = NULL;
	lst_env = NULL;
	status = 1;
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	lst_env = env_to_lst(envp);
	if (lst_env == NULL)
		printf("erro");
	define_signals();
	while (status)
	{
		cmd = readline("MiniHELL>>");
		if (cmd == NULL)
			status = 0;
		else
		{
			ft_add_history(cmd);
			cmd_tkn = tokenizer(cmd, cmd_tkn);
			status = builtin_all(cmd, &lst_env, status);
		}
	}
	free_all(&lst_env, cmd, cmd_tkn);
}
