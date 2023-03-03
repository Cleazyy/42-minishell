/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 11:30:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	allocate_size(char **envp, char *var)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) != 0)
			size++;
		i++;
	}
	return (size);
}

static char	**fill_unset_envp(char **final, char **envp, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) != 0)
		{
			final[j] = ft_strdup(envp[i]);
			if (!final[j])
			{
				free_array(final);
				return (NULL);
			}
			j++;
		}
		free(envp[i]);
		i++;
	}
	free(envp);
	final[j] = NULL;
	return (final);
}

static char	**remove_var_envp(char **envp, char *var)
{
	char	**final;

	final = malloc(sizeof(char *) * (allocate_size(envp, var) + 1));
	if (!final)
		return (NULL);
	final = fill_unset_envp(final, envp, var);
	return (final);
}

int	ft_unset(t_data *data, t_cmds *cmds)
{
	char	*temp;
	int		i;

	if (!cmds->str[1])
		return (0);
	if (!is_correct_unset_var(cmds))
		return (1);
	i = 1;
	while (cmds->str[i])
	{
		temp = ft_strjoin(cmds->str[i], "=");
		data->envp = remove_var_envp(data->envp, temp);
		free(temp);
		i++;
	}
	print_envp(data);
	return (0);
}
