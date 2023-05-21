/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:46:14 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/21 18:57:20 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	give_id(t_list *data, t_philo **philos)
{
	int			i;
	t_philo		*philos;

	i = 1;
	while (i <= data->number_philo)
	{
		ft_add_philo(philos, data, i);
		i++;
	}
}

t_list	*ft_lstnew(int philo, int die, int eat, int sleep)
{
	t_list			*data;

	data = (t_list *)malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data -> number_philo = philo;
	data->time_die = die;
	data->time_eat = eat;
	data->time_sleep = sleep;
	return (data);
}

void	ft_add_philo(t_philo **lst, t_list *data, int p_id)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	new_node->p_id = p_id;
	new_node->list = data;
	pthread_mutex_init(&new_node->fork, NULL);
	if (*lst == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*lst = new_node;
		return ;
	}
	new_node->prev = (*lst)->prev;
	new_node->next = (*lst);
	(*lst)->prev = new_node;
}

