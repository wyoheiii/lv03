/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:49 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/14 12:55:45 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*philo_table(void *p)
{
	t_philo	*philo;

	philo = p;
	pthread_mutex_lock(&philo->d->common_protect);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->d->common_protect);
	if (philo->num % 2 == 0)
		usleep((philo->d->eat_time * 1000) - 200);
	while (1)
	{
		if (!philo_eat_beefbowl(philo))
			break ;
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
	}
	return (NULL);
}

bool	thread_main(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &philo_table, \
					&data->philo[i]) != 0)
			return (print_error("create error\n"));
		i++;
	}
	if (pthread_create(&data->starvation_monitor, NULL, &dead_monitor, \
				data) != 0)
		return (print_error("create error\n"));
	j = 0;
	while (j < data->philo_num)
	{
		if (pthread_join(data->philo[j].thread, NULL) != 0)
			return (print_error("join error\n"));
		j++;
	}
	if (pthread_join(data->starvation_monitor, NULL) != 0)
		return (print_error("join error\n"));
	return (true);
}
