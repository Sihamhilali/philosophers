/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/19 17:40:14 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"


int	main(int argc, char **argv)
{
	int		i;
	char	*join;
	char	**table;
	t_list	*data;

	i = 0;
	join = NULL;
	if (argc > 4 && argc <= 5)
	{
		empty(argv);
		isital(data);
		while (argv[i])
			join = ft_strjoin(join, argv[i++]);
		table = ft_split(join, ' ');
		free(join);
		data->table = table;
		max_min(table);
		is_numbre(table);
		data->number_philo = ft_atoi(argv[1]);
		data->time_eat = ft_atoi(argv[2]);
		data->time_sleep = ft_atoi(argv[3]);
		data->time_die = ft_atoi(argv[4]);
	}

}
