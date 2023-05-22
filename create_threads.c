/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/22 17:36:16 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*func(void *ana)
{
	t_philo *ptr = (t_philo *)ana;
	//int i = 0;
	//while(1)
	//{
		//pthread_mutex_lock(&ptr->fork);
		printf(" hi im thread  %d\n", ptr->p_id);
		//pthread_mutex_unlock(&ptr->fork);
	//}
	return (NULL);
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
