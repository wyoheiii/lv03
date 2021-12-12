/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:39 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/12 14:38:08 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static bool	print_action(t_philo *p, int action)
{
	pthread_mutex_lock(&p->d->common_protect);
	if (!p->d->end_flag)
	{
		if (action == FORK)
			printf("%ld %d has taken a fork\n", get_time(), p->num);
		else if (action == EAT)
		{
			printf("%ld %d is eating\n", get_time(), p->num);
			p->last_eat_time = get_time();
			p->eat_count++;
			if (p->eat_count == p->d->max_eat_num)
				p->d->philos_eat_count++;
			if (p->d->philos_eat_count == p->d->philo_num)
				p->d->end_flag = 1;
		}
		else if (action == SLEEP)
			printf("%ld %d is sleeping\n", get_time(), p->num);
		else if (action == THINK)
			printf("%ld %d is thinking\n", get_time(), p->num);
		pthread_mutex_unlock(&p->d->common_protect);
		return (true);
	}
	pthread_mutex_unlock(&p->d->common_protect);
	return (false);
}

static void	one_philo(t_philo *p)
{
	pthread_mutex_lock(&p->d->fork[p->r_fork]);
	if (!print_action(p, FORK))
		return ;
	while (!p->d->end_flag)
		usleep(100);
}

bool	philo_eat_beefbowl(t_philo *p)
{
	if (p->d->philo_num == 1)
	{
		one_philo(p);
		return (false);
	}
	pthread_mutex_lock(&p->d->fork[p->r_fork]);
	if(!print_action(p, FORK))
	{
		pthread_mutex_unlock(&p->d->fork[p->r_fork]);
		return(false);
	}
	pthread_mutex_lock(&p->d->fork[p->l_fork]);
	print_action(p, FORK);
	print_action(p, EAT);
	while ((get_time() - p->last_eat_time) <= p->d->eat_time \
			&& !p->d->end_flag)
		usleep(100);
	pthread_mutex_unlock(&p->d->fork[p->r_fork]);
	pthread_mutex_unlock(&p->d->fork[p->l_fork]);
	return (true);
}

bool	philo_sleep(t_philo *p)
{
	size_t	sleep;

	if (!print_action(p, SLEEP))
		return (false);
	sleep = get_time();
	while ((get_time() - sleep) <= p->d->sleep_time && \
			!p->d->end_flag)
		usleep(100);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (!print_action(philo, THINK))
		return (false);
	usleep(100);
	return (true);
}
