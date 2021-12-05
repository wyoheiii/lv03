/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:32 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/05 00:01:38 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t get_time(void)
{
	struct timeval time;

	if(gettimeofday(&time, NULL) == -1)
		return(print_error("gettimeofday error\n"));
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
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
		return(FAILURE);
	if (str[0] == '0')
		return(FAILURE);
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		if (total > INT_MAX && check == 1)
			return(FAILURE);
		i++;
	}
	return ((size_t)(total));
}
