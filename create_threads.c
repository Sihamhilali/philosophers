/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/28 17:40:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	fork_right(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->fork);
	pthread_mutex_lock(&ptr->list->write);
	printf("%ld %d Take fork 1\n", cureent_time(ptr), ptr->p_id);
	pthread_mutex_unlock(&ptr->list->write);
}

void	fork_left(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->next->fork);
	pthread_mutex_lock(&ptr->list->write);
	printf("%ld %d Take fork 2\n", cureent_time(ptr), ptr->p_id);
	pthread_mutex_unlock(&ptr->list->write);
}

void	is_eating(t_philo *ptr)
{
	ptr->eat++;
	pthread_mutex_lock(&ptr->list->write);
	printf("%ld %d is eating\n", cureent_time(ptr), ptr->p_id);
	pthread_mutex_unlock(&ptr->list->write);
	ptr->last_eat = get_time();
	ft_usleep(ptr->list->time_eat);
}

void	forks_down(t_philo *ptr)
{
	pthread_mutex_unlock(&ptr->fork);
	pthread_mutex_lock(&ptr->list->write);
	printf("%ld %d down fork 1\n", cureent_time(ptr), ptr->p_id);
	pthread_mutex_unlock(&ptr->list->write);
	pthread_mutex_unlock(&ptr->next->fork);
	pthread_mutex_lock(&ptr->list->write);
	printf("%ld %d down fork 2\n", cureent_time(ptr), ptr->p_id);
	pthread_mutex_unlock(&ptr->list->write);
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
		ft_usleep(ptr->list->time_sleep);
	}
	return (NULL);
}

void	ft_start(t_philo *thread)
{
	t_philo	*lst;
	int		i;

	lst = thread;
	i = 0 ;
	pthread_mutex_init(&thread->list->write, NULL);
	while (i < thread->list->number_philo)
	{
		pthread_create(&lst->threads, NULL, &func, thread);
		thread = thread->next;
		usleep(500);
		i++;
	}
	die(lst);
}
