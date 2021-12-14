/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:34 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/14 12:54:33 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static bool	starvation_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->common_protect);
		if (data->end_flag)
		{
			pthread_mutex_unlock(&data->common_protect);
			return (true);
		}
		if ((get_time() - data->philo[i].last_eat_time) > data->die_time \
				&& !data->end_flag)
		{
			data->end_flag = 1;
			printf("%ld %d died\n", get_time(), data->philo[i].num);
			pthread_mutex_unlock(&data->common_protect);
			return (true);
		}
		pthread_mutex_unlock(&data->common_protect);
		i++;
	}
	return (false);
}

void	*dead_monitor(void *d)
{
	t_data	*data;

	data = d;
	while (1)
	{
		if (starvation_check(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
