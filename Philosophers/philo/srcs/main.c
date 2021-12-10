/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:52:41 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/10 18:10:44 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!av_check(ac, av))
			return (FAILURE);
		if (!init(ac, av, &data))
			return (FAILURE);
		if (!thread_main(&data))
		{
			god_free(&data);
			return (FAILURE);
		}
		god_free(&data);
		return (SUCCESS);
	}
	return (print_error("ac_error\n"));
}
