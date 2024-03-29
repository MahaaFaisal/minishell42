/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:39 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/28 15:54:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_token(char **array, char *string)
{
	int		i;
	char	**splitted;

	splitted = ft_split(string, 32);
	if (!splitted)
		return (NULL);
	i = 0;
	while (splitted[i])
	{
		array = append_to_array(array, ft_strdup(splitted[i]));
		i++;
	}
	ft_free(splitted);
	return (array);
}

void	split_by_space(t_mshell *shell)
{
	char	**new_tokens;
	int		i;

	i = 0;
	new_tokens = malloc (1 * sizeof (char *));
	if (!new_tokens)
		return ;
	new_tokens[0] = NULL;
	while (shell->tokens[i])
	{
		if (!ft_strset(shell->tokens[i], "\"\'"))
		{
			new_tokens = split_token(new_tokens, shell->tokens[i]);
			if (!new_tokens)
				return ;
		}
		else
			new_tokens = append_to_array(new_tokens,
					ft_strdup(shell->tokens[i]));
		i++;
	}
	ft_free(shell->tokens);
	shell->tokens = new_tokens;
}
