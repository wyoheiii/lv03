/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:25:54 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/11 20:29:03 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static bool	fork_init(t_data *data)
{
	int	i;

	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (data->fork == NULL)
		return (print_error("malloc error\n"));
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (print_error("mutex_init error\n"));
		i++;
	}
	return (true);
}

static bool	idx_check(t_data *data, int ac)
{
	if (ac == 6 && data->max_eat_num == FAILURE)
		return (print_error("args num error\n"));
	if (data->philo_num == FAILURE \
			|| data->die_time == FAILURE \
			|| data->eat_time == FAILURE \
			|| data->sleep_time == FAILURE)
		return (print_error("args num error\n"));
	return (true);
}

static bool	philo_init(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	if (data->philo == NULL)
		return (print_error("malloc error\n"));
	i = 0;
	while (i < data->philo_num)
	{
		data->philo[i].num = i + 1;
		data->philo[i].l_fork = i;
		if (i + 1 == data->philo_num)
			data->philo[i].r_fork = 0;
		else
			data->philo[i].r_fork = i + 1;
		data->philo[i].d = data;
		data->philo[i].eat_count = 0;
		i++;
	}
	return (true);
}

static bool	init2(int ac, t_data *data)
{
	if (!idx_check(data, ac))
		return (false);
	if (!philo_init(data))
	{
		god_free(data);
		return (false);
	}
	if (!fork_init(data))
	{
		god_free(data);
		return (false);
	}
	return (true);
}

bool	init(int ac, char **av, t_data *data)
{
	if (ac == 6)
		data->max_eat_num = atooooi(av[5]);
	else
		data->max_eat_num = 0;
	data->philo_num = (int)atooooi(av[1]);
	data->die_time = atooooi(av[2]);
	data->eat_time = atooooi(av[3]);
	data->sleep_time = atooooi(av[4]);
	data->end_flag = 0;
	data->philos_eat_count = 0;
	data->fork = NULL;
	data->philo = NULL;
	if (pthread_mutex_init(&data->common_protect, NULL) != 0)
		return (print_error("mutex_init error\n"));
	if (!init2(ac, data))
		return (false);
	return (true);
}
