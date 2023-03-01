/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/01 07:51:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unset_args(t_cmds *cmds)
{
	int	i;
	int	j;

	i = 1;
	while (cmds->str[i])
	{
		j = 0;
		while (cmds->str[i][j])
		{
			if (!is_valid_var_name(&cmds->str[i][j]))
			{
				ft_putstr_fd("minishell: unset: `", 2);
				ft_putstr_fd(cmds->str[i], 2);
				ft_putendl_fd("': not a valid identifier", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_unset(t_data *data, t_cmds *cmds)
{
	(void) data;
	if (!cmds->str[1])
		return (0);
	if (!check_unset_args(cmds))
		return (1);
	return (0);
}
