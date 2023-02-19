/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/19 07:03:45 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_create(int *old_in, int last)
{
	int	pipe_new[2];

	dup2(*old_in, STDIN_FILENO);
	if (*old_in != 0)
		close(*old_in);
	if (last)
		return ;
	pipe(pipe_new);
	dup2(pipe_new[1], STDOUT_FILENO);
	close(pipe_new[1]);
	*old_in = dup(pipe_new[0]);
	close(pipe_new[0]);
}

void	builtin_pipe(char *cmd, t_list **envp, int *old_in, int last)
{
	int		fd_saved[2];
	char	**cmd_tkn;

	cmd_tkn = NULL;
	fd_saved[0] = dup(STDIN_FILENO);
	fd_saved[1] = dup(STDOUT_FILENO);
	pipe_create(old_in, last);
	// printf("comando ao entrar no 2 tokenizer ->$%s\n\n", cmd);
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp, 1);
	cmd_tkn = redirect_verify(cmd_tkn, old_in);
	builtin_all(cmd, envp, cmd_tkn);
	dup2(fd_saved[0], STDIN_FILENO);
	close(fd_saved[0]);
	dup2(fd_saved[1], STDOUT_FILENO);
	close(fd_saved[1]);
	free_tkn(cmd_tkn);
}

void	line_in_pipe(char **split_token, t_list **envp, int *old_in, int id)
{
	if (split_token[id + 1])
	{
		builtin_pipe(split_token[id], envp, old_in, 0);
		line_in_pipe(split_token, envp, old_in, id + 1);
	}
	else
		builtin_pipe(split_token[id], envp, old_in, 1);
}

int	cont_pipe_token(char **cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (*tmp)
	{
		if (!ft_strncmp(*tmp, "|", 1))
			i++;
		tmp++;
	}
	return (i);
}

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int		old_in;
	char	**split_token;
	char	**cmd_tkn;
	// int i = 0;

	if(have_two_quotes(cmd) == -1)
	{
		status_error("Invalid caracter, aspas nao fechadas", ERROR);
		return ;
	}
	old_in = 0;
	cmd_tkn = NULL;
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp, 0);
	// while (cmd_tkn[i])
	// 	printf("comando depois do tokenizer ->$%s\n\n", cmd_tkn[i++]);
	if (verify_cmd(cmd_tkn) == -1)
	{
		status_error("Invalid caracter", ERROR);
		return ;
	}
	else
	{
		split_token = ft_split_token(cmd_tkn);
		// printf("comando dps do split_token tokenizer ->$%s\n\n", *split_token);
		// printf("---------------------------\n");
		line_in_pipe(split_token, envp, &old_in, 0);
		free_tkn(split_token);
	}
	if (old_in != 0)
		close(old_in);
}
