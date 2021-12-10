/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:34 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/10 18:11:35 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*dead_monitor(void *d)
{
	t_data	*data;
	int		i;

	data = d;
	while (!data->end_flag)
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->common_protect);
			if ((get_time() - data->philo[i].last_eat_time) > data->die_time \
					&& !data->end_flag)
			{
				data->end_flag = 1;
				printf("%ld %d died\n", get_time(), data->philo[i].num);
				pthread_mutex_unlock(&data->common_protect);
				break ;
			}
			pthread_mutex_unlock(&data->common_protect);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
