/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/21 18:58:04 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	valid(int i, char **table)
{
	int	k;

	k = 0;
	while (k < i)
	{
		empty(table);
		max_min(table);
		is_numbre(table);
		k++;
	}
}


int	main(int argc, char **argv)
{
	int		i;
	t_list	*data;
	t_philo *philos;

	i = 0;
	data = NULL;
	if (argc >= 5 || argc <= 6)
	{
		valid(argc, argv);
		t_lstnew(ft_atoi(argv[1]), ft_atoi(argv[2]),
			ft_atoi(argv[3]), ft_atoi(argv[4]));
		if (argc == 6)
			data->max_eat = ft_atoi(argv[5]);
		else
			data->max_eat = -1;
		give_id(data, &philos);
		ft_start(philos);
	}
	else
		printf("Error size of argument");

}
