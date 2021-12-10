/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:48 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/10 21:58:55 by wyohei           ###   ########.fr       */
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

static int	ft_isdigit(int	c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (-1);
}

static bool	check_args(char	*str)
{
	size_t		i;
	int			flag;

	i = 0;
	if (ft_strlen(str) > 11)
		return (false);
	if (str[0] == '-')
		return (false);
	if (str[0] == '0' && str[1] != '\0')
		return (false);
	while (str[i] != '\0')
	{
		flag = ft_isdigit(str[i]);
		if (flag == -1)
			return (false);
		i++;
	}
	return (SUCCESS);
}

bool	av_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_args(av[i]))
			return (print_error("args string error\n"));
		i++;
	}
	return (true);
}
