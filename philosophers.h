/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:30:39 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/04 12:54:43 by selhilal         ###   ########.fr       */
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
int		empty(char **str);
int		is_numbre(char **split);

typedef struct s_list
{
	int				max_eat;
	int				number_philo;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				eats;
	long			start_time;
	pthread_mutex_t	last;
	pthread_mutex_t	eat_first;
	pthread_mutex_t	write;
	pthread_mutex_t	die;
	int				dead;
}				t_list;

typedef struct s_philo
{
	int				p_id;
	pthread_mutex_t	fork;
	pthread_t		threads;
	t_list			*list;
	long			last_eat;
	int				eat;
	struct s_philo	*next;
}				t_philo;

long	get_time(void);
long	cureent_time(t_philo *philo);
int		ft_usleep(unsigned int time);
void	give_id(t_list *data, t_philo **philos);
int		ft_start(t_philo *thread);
void	*func(void *ana);
int		die(t_philo *philos);
void	ft_printf(t_philo *ptr, char *str);
#endif