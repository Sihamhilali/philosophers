/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/06 16:30:53 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free(t_philo *philo, t_list *list)
{
	while (philo)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
	}
	pthread_mutex_destroy(&list->last);
	pthread_mutex_destroy(&list->eat_first);
	pthread_mutex_destroy(&list->write);
	free(&list);
}

void	init(t_list *data, char **argv, int argc)
{
	data->dead = 0;
	data->number_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
			data->max_eat = -1;
	data->start_time = get_time();
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_list	*data;

	philos = NULL;
	if (argc != 5 && argc != 6)
		printf("Error size of argument");
	else
	{
		data = malloc(sizeof(t_list));
		if (!data)
			return (0);
		init(data, argv, argc);
		if (data->number_philo <= 0 || data->time_die < 0
			||data->time_eat < 0 || data->time_sleep < 0
			|| !empty(argv) || !is_numbre(argv))
			return (printf("%s\n", "Error in the numbers"), free(data), 0);
		give_id(data, &philos);
		if (ft_start(philos) == 1)
			return (1);
		ft_free(philos, data);
	}
	return (0);
}
