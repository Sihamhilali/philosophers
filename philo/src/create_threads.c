/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/06 16:30:40 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

void	fork_right(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->fork);
	ft_printf(ptr, "%ld %d has taken a fork\n");
}

void	fork_left(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->next->fork);
	ft_printf(ptr, "%ld %d has taken a fork\n");
}

void	is_eating(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->list->eat_first);
	ptr->eat++;
	pthread_mutex_unlock(&ptr->list->eat_first);
	ft_printf(ptr, "%ld %d is eating\n");
	pthread_mutex_lock(&ptr->list->last);
	ptr->last_eat = get_time();
	pthread_mutex_unlock(&ptr->list->last);
	ft_usleep(ptr->list->time_eat);
}

void	forks_down(t_philo *ptr)
{
	pthread_mutex_unlock(&ptr->fork);
	pthread_mutex_unlock(&ptr->next->fork);
}

void	*func(void *ana)
{
	t_philo	*ptr;

	ptr = (t_philo *)ana;
	while (1)
	{
		fork_right(ptr);
		fork_left(ptr);
		is_eating(ptr);
		forks_down(ptr);
		ft_printf(ptr, "%ld %d is sleeping\n");
		ft_usleep(ptr->list->time_sleep);
		ft_printf(ptr, "%ld %d is thinking\n");
	}
	return (NULL);
}
