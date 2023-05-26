/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:07:19 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/26 18:35:46 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	empty(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (str[i])
	{
		count = 0;
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ' || str[i][j] == '\t')
				count++;
			j++;
		}
		if (ft_strlen(str[i]) == count)
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(char const *str)
{
	int		i;
	int		signe;
	long	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		somme = somme * 10 + str[i] - '0';
		i++;
	}
	return (somme * signe);
}

int	ft_isdigit(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		count++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			count++;
		}
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}

int	is_numbre(char **split)
{
	int		j;

	j = 1;
	while (split[j])
	{
		if (ft_isdigit(split[j]) == 1)
			j++;
		else
			return (0);
	}
	return (1);
}
