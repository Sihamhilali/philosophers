/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:52:41 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/26 18:05:16 by selhilal         ###   ########.fr       */
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

int	ft_usleep(unsigned int time, t_philo	*philo)
{
	while ((get_time() - philo->list->start_time) < time)
		usleep(time / 10);
	return (0);
}
