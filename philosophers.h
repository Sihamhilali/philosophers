/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:30:39 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/24 20:44:02 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
# include <time.h>
# include <sys/time.h>


int		ft_strlen(const char *s);
long	ft_atoi(char const *str);
void	empty(char **str);
void	max_min(char **split);
void	is_numbre(char **split);

typedef struct s_list
{
	int				max_eat;
	int				number_philo;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				start_eat;
	int				finish_eat;
	pthread_mutex_t	write;
	int				start_think;
}				t_list;

typedef struct s_philo
{
	int				p_id;
	pthread_mutex_t	fork;
	pthread_t		threads;
	t_list			*list;
	struct s_philo	*next;
}				t_philo;

void	creat_philosoper(t_list *thread);
void	ft_lstadd_back(t_philo	**lst, t_list	*new);
void	give_id(t_list *data, t_philo **philos);
void	ft_start(t_philo *thread);
#endif