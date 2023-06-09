/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:46:14 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/06 16:30:50 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

t_philo	*ft_lstlast(t_philo	*lst)
{
	t_philo	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != lst)
		tmp = tmp->next;
	return (tmp);
}

void	ft_add_philo(t_philo **lst, t_list *data, int p_id)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	if (!new_node)
		return ;
	new_node->p_id = p_id;
	new_node->list = data;
	new_node->last_eat = get_time();
	new_node->eat = -1;
	new_node->list->eats = 0;
	pthread_mutex_init(&new_node->fork, NULL);
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->next = *lst;
		return ;
	}
	ft_lstlast(*lst)->next = new_node;
	new_node->next = *lst;
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

int	ft_start(t_philo *thread)
{
	t_philo	*lst;
	int		i;

	lst = thread;
	i = 0 ;
	pthread_mutex_init(&(thread->list->write), NULL);
	pthread_mutex_init(&thread->list->eat_first, NULL);
	pthread_mutex_init(&thread->list->last, NULL);
	pthread_mutex_init(&thread->list->die, NULL);
	while (i < thread->list->number_philo)
	{
		pthread_create(&lst->threads, NULL, &func, thread);
		pthread_detach(lst->threads);
		thread = thread->next;
		usleep(200);
		i++;
	}
	if (die(lst) == 1)
		return (1);
	return (0);
}
