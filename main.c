/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/24 18:09:28 by selhilal         ###   ########.fr       */
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

void	init_pro(t_list data, char **argv, int argc)
{
	data.start_eat = 0;
	data.finish_eat = 0;
	data.start_think = 0;
	data.number_philo = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.max_eat = ft_atoi(argv[5]);
	else
		data.max_eat = 0;
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
		empty(argv);
		max_min(argv);
		is_numbre(argv);
		init_pro(data, argv, argc);
		give_id(&data, &philos);
		ft_start(philos);
	}

}
