/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/28 17:41:28 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	die(t_philo *philos)
{
	t_philo	*tmp;

	tmp = philos;
	while (tmp)
	{
		if (tmp->list->max_eat > -1)
		{
			if (tmp->eat >= tmp->list->max_eat)
			{
				printf("--%d\n", tmp->list->eats);
				tmp->list->eats++;
			}
			if (tmp->list->eats >= tmp->list->number_philo)
			{
				printf("all have eat\n");
				exit(1);
			}
		}
		if (get_time() - tmp->last_eat > tmp->list->time_die)
		{
			printf("%ld %d is die\n", cureent_time(tmp), tmp->p_id);
			exit(1);
		}
		tmp = tmp->next;
	}
}
