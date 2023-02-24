/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:39:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:34 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_pwd(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
		{
			len = ft_strlen(data->envp[i]) - 4;
			data->pwd = ft_substr(data->envp[i], 4, len);
		}
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
		{
			len = ft_strlen(data->envp[i]) - 7;
			data->old_pwd = ft_substr(data->envp[i], 7, len);
		}
		i++;
	}
	return (1);
}