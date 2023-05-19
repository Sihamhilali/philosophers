/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:07:19 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/19 15:46:05 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	empty(char **str)
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
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
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

void	max_min(char **split)
{
	long	num1;
	int		n;

	n = 0;
	while (split[n])
	{
		num1 = ft_atoi(split[n]);
		if (num1 < 0 || num1 > 2147483648)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		n++;
	}
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

void	is_numbre(char **split)
{
	int		j;

	j = 0;
	while (split[j])
	{
		if (ft_isdigit(split[j]) == 1)
			j++;
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}
