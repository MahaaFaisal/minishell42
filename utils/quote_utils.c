/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:54:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 18:46:50 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_quote(char **str, char *next_str)
{
	char	*temp;

	if (ft_strset(next_str, "\'\""))
	{
		temp = ft_strdup("\"");
		temp = ft_strjoin(temp, *str);
		temp = ft_strjoin(temp, "\"");
		free(*str);
		*str = temp;
	}
}
