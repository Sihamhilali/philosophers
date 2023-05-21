/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:30:39 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/21 16:24:41 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>


typedef struct s_list
{
	int				max_eat;
	int				number_philo;
	int				time_eat;
	int				time_sleep;
	int				time_die;
}				t_list;

typedef struct s_philo
{
	int				p_id;
	pthread_mutex_t	fork;
	pthread_t		threads;
	t_list			*list;
	struct s_philo	*next;
	struct s_philo	*prev;

}				t_philo;

int		ft_strlen(const char *s);
long	ft_atoi(char const *str);
void	empty(char **str);
void	max_min(char **split);
void	is_numbre(char **split);
void	isital(t_list *thread);


void	creat_philosoper(t_list *thread);
t_list	*ft_lstnew(int philo, int die, int eat, int sleep);
void	ft_lstadd_back(t_philo	**lst, t_list	*new);

#endif