/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:52:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/19 17:58:34 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

t_list	isital(t_list *thread)
{
	thread->number_philo = 0;
	thread->threads = 0;
	thread->table = NULL;
	thread->time_die = 0;
	thread->time_eat = 0;
	thread->time_sleep = 0;
}
