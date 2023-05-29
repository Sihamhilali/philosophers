/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:22:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/29 21:14:21 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	cureent_time(t_philo *philo)
{
	return (get_time() - philo->list->start_time);
}

int	ft_usleep(unsigned int time)
{
	long	now;

	now = get_time();
	while (get_time() < time + now)
		usleep(500);
	return (0);
}

int	die(t_philo *philos)
{
	t_philo	*tmp;

	tmp = philos;
	while (tmp)
	{
		if (tmp->list->max_eat > -1)
		{
			pthread_mutex_lock(&tmp->list->eat_first);
			if (tmp->eat >= tmp->list->max_eat)
				tmp->list->eats++;
			if (tmp->list->eats >= tmp->list->number_philo)
				return (0);
			pthread_mutex_unlock(&tmp->list->eat_first);
		}
		pthread_mutex_lock(&tmp->list->last);
		if (get_time() - tmp->last_eat > tmp->list->time_die)
		{
			pthread_mutex_unlock(&tmp->list->last);
			printf("%ld %d is die\n", cureent_time(tmp), tmp->p_id);
			return (0);
		}
		pthread_mutex_unlock(&tmp->list->last);
		tmp = tmp->next;
	}
	return (0);
}
