/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/24 20:58:30 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*func(void *ana)
{
	t_philo *ptr = (t_philo *)ana;

	while (1)
	{
		pthread_mutex_lock(&ptr->fork);
		printf("Take fork 1 %d\n", ptr->p_id);
		pthread_mutex_lock(&ptr->list->write);
		printf(" hi im thread  %d\n", ptr->p_id);
		pthread_mutex_unlock(&ptr->list->write);
		usleep(500);
	}
	
	//
		//pthread_mutex_lock(ptr->fork);
		// printf(" hi im thread  %d\n", ptr->p_id);
		//pthread_mutex_unlock(ptr->fork);
	return (NULL);
}

void	circuler(t_philo	*lst)
{
	while (lst)
	{
		if (lst->p_id % 2 == 0)
		{
			// sleep()
			pthread_mutex_lock(&lst->fork);
			pthread_mutex_lock(&lst->next->fork);
		}
		lst = lst->next;
	}

}

void	ft_start(t_philo *thread)
{
	t_philo	*lst;
	int		i;

	lst = thread;
	i =0 ;
	pthread_mutex_init(&thread->list->write, NULL);
	while (i < thread->list->number_philo)
	{
		pthread_create(&lst->threads, NULL, &func, thread);
		// pthread_detach(thread->threads);
		thread = thread->next;
		usleep(500);
		i++;
	}
	while(1);
	// circuler(lst);
}
