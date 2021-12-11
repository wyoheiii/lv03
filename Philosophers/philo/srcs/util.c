/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:32 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/11 20:25:13 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
bool	print_error(char *error)
{
	printf("%s", error);
	return (false);
}

void	god_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->common_protect);
	if (data->philo != NULL)
		free(data->philo);
	if (data->fork != NULL)
		free(data->fork);
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	atooooi(const char	*str)
{
	size_t		i;
	long long	check;
	long long	total;

	check = 1;
	total = 0;
	i = 0;
	if (str[i] == '-')
		return (FAILURE);
	if (str[i] == '0')
		return (FAILURE);
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		if (total > INT_MAX && check == 1)
			return (FAILURE);
		if (total > TIME_MAX)
			return (FAILURE);
		i++;
	}
	return ((size_t)(total));
}
