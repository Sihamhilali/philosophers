/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:46:14 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/22 17:38:17 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_add_philo(t_philo **lst, t_list *data, int p_id)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	if (!new_node)
		return ;
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
	(*lst)->prev->next = new_node;
	(*lst)->prev = new_node;
}

void	give_id(t_list *data, t_philo **philos)
{
	int			i;

	i = 1;
	while (i <= data->number_philo)
	{
		ft_add_philo(philos, data, i);
		i++;
	}
}
