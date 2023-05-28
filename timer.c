/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:52:41 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/28 17:38:30 by selhilal         ###   ########.fr       */
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
