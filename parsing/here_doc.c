/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:33 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/30 17:28:35 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	duplicate_heredoc(int fd)
// {
	
// }

int	here_doc(t_mshell *shell, char *name)
{
	int		fd[2];
	pid_t	pid;
	char	*line;
	char	*delimiter;

	if (pipe(fd) < 0)
		return (ft_putendl_fd("Error creating pipe", 2), -1);
		// return ;
	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		return (-1);
	}
	if (!pid)
	{
		close(fd[0]);
		if (signal(SIGINT, heredoc_handler) == SIG_ERR)
			perror("SIGQUIT Error");
		line = get_next_line(0);
		if (!is_quote(*name))
			delimiter = ft_str_join(name, "\n");
		else
			delimiter = ft_strjoin(custom_trim(ft_strdup(name), *name, 0), "\n");
		while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) != 0)
		{
			if (!is_quote(*name))
				expand_string(shell, &line);
			ft_putstr_fd(line, fd[1]);
			free(line);
			line = get_next_line(0);
		}
		free(delimiter);
		free(line);
		exit(0);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, &shell->exit_code, 0);
		shell->exit_code = WEXITSTATUS(shell->exit_code);
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			perror("SIGQUIT Error");
		if (shell->exit_code != 0)
		{
			// check_signal(shell);
			close(fd[0]);
			// if (dup2(fd[0], STDIN_FILENO) < 0)
			// 	perror("Here_doc");
			return (-1);
		}
	}
	check_signal(shell);
	return (fd[0]);
}