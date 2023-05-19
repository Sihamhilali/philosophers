/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:30:39 by selhilal          #+#    #+#             */
/*   Updated: 2023/05/19 18:13:21 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
long	ft_atoi(char const *str);
void	empty(char **str);
void	max_min(char **split);
void	is_numbre(char **split);
void	isital(t_list *thread);
//void	creat_philosoper(t_list *thread);

//typedef struct s_list
//{
//	char		**table;
//	int			number_philo;
//	int			time_eat;
//	int			time_sleep;
//	int			time_die;
//	pthread_t	threads;
//}				t_list;

typedef struct s_linked
{
	int				content;
	int				index;
	struct s_linked	*next;
}					t_linked;

#endif