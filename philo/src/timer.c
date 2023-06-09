/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:22:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/06 16:30:55 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

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
		usleep(200);
	return (0);
}

int	die(t_philo *philos)
{
	t_philo	*tmp;

	tmp = philos;
	while (tmp->next != NULL)
	{
		if (tmp->list->max_eat > -1)
		{
			pthread_mutex_lock(&tmp->list->eat_first);
			if (tmp->eat == tmp->list->max_eat)
			tmp->list->eats++;
			if (tmp->list->eats >= tmp->list->number_philo)
				return (pthread_mutex_lock(&tmp->list->die),
					tmp->list->dead = 1,
					pthread_mutex_unlock(&tmp->list->die), 1);
			pthread_mutex_unlock(&tmp->list->eat_first);
		}
		pthread_mutex_lock(&tmp->list->last);
		if (get_time() - tmp->last_eat > tmp->list->time_die)
			return (pthread_mutex_lock(&tmp->list->die), tmp->list->dead = 1,
				pthread_mutex_unlock(&tmp->list->die),
				pthread_mutex_unlock(&tmp->list->last),
				printf("%ld %d died\n", cureent_time(tmp), tmp->p_id), 1);
		pthread_mutex_unlock(&tmp->list->last);
	}
	return (0);
}
