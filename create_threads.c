/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:13:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/21 18:58:58 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*func(void *ana)
{
	(void)ana;
	printf("hi im thread");
	return (NULL);
}

void	ft_start(t_philo *thread)
{
	int	i;
	int	j;

	i = thread->list->number_philo;
	j = 0;
	while (j < i)
	{

		pthread_create(&thread->threads, NULL, func, NULL);
		i++;
	}
}

