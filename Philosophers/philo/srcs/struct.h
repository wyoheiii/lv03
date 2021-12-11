/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:53 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/11 20:24:42 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_data	t_data;
typedef struct s_philo
{
	int				eat_count;
	int				num;
	int				l_fork;
	int				r_fork;
	size_t			last_eat_time;
	pthread_t		thread;
	t_data			*d;
}	t_philo;

typedef struct s_data
{
	int				philo_num;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				max_eat_num;
	int				fork_num;
	int				end_flag;
	int				philos_eat_count;
	pthread_mutex_t	*fork;
	pthread_mutex_t	common_protect;
	pthread_t		starvation_monitor;
	t_philo			*philo;
}	t_data;

#endif
