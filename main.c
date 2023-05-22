/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/22 17:37:03 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	data;
	t_philo	*philos;
	int		i;

	i = 1;
	if (argc != 5 && argc != 6)
		printf("Error size of argument");
	else
	{
		empty(argv);
		max_min(argv);
		is_numbre(argv);
		data.number_philo = ft_atoi(argv[1]);
		data.time_die = ft_atoi(argv[2]);
		data.time_eat = ft_atoi(argv[3]);
		data.time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data.max_eat = ft_atoi(argv[5]);
		else
			data.max_eat = 0;
		give_id(&data, &philos);
		ft_start(philos);
	}

}
