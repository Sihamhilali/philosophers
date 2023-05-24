/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/24 17:29:58 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*func(void *ana)
{
	t_philo *ptr = (t_philo *)ana;
//	ptr->list->start_eat = 
		//pthread_mutex_lock(&ptr->fork);
		printf(" hi im thread  %d\n", ptr->p_id);
		//pthread_mutex_unlock(&ptr->fork);
	//}
	return (NULL);
}

void	circuler(t_philo	*lst)
{
	while (lst)
	{
		if (lst->p_id % 2 == 0)
		{
			pthread_mutex_lock(lst->fork);
			pthread_mutex_lock(lst->next->fork);
		}
	}

}

void	ft_start(t_philo *thread)
{
	t_philo	*lst;

	lst = thread;
	while (thread)
	{
		pthread_create(&lst->threads, NULL, &func, lst);
		pthread_detach(thread->threads);
		thread = thread->next;
		if (thread == lst)
			break ;
		lst = lst->next;
	}
}
