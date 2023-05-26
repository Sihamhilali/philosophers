/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/26 20:35:13 by selhilal         ###   ########.fr       */
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
	philos = NULL;
	if (argc != 5 && argc != 6)
		printf("Error size of argument");
	else
	{
		if (!empty(argv) || !is_numbre(argv))
		{
			printf("%s\n", "Error in the numbers");
			return (0);
		}
		data.number_philo = ft_atoi(argv[1]);
		data.time_die = ft_atoi(argv[2]);
		data.time_eat = ft_atoi(argv[3]);
		data.time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data.max_eat = ft_atoi(argv[5]);
		else
			data.max_eat = 0;
		if (data.number_philo <= 0 || data.time_die < 0
			||data.time_eat < 0 || data.time_sleep < 0)
		{
			printf("%s\n", "Error in the numbers");
			return (0);
		}
		data.start_time = get_time();
		give_id(&data, &philos);
		ft_start(philos);
		pthread_mutex_destroy(&philos->fork);
	}

}
