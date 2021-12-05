/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabeyouhei <watanabeyouhei@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:25:54 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/05 15:35:37 by watanabeyou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool idx_check(t_data *data, int ac)
{
    if(ac == 6 && data->op_eat_num == FAILURE)
        return(print_error("args num error\n"));
    if (data->philo_num == FAILURE \
        || data->die_time == FAILURE \
        || data->eat_time == FAILURE \
        || data->sleep_time == FAILURE)
        return(print_error("aargs num error\n"));
    return(true);
}
static bool philo_init(t_data *data)
{
    int i;
    data->philo = malloc(sizeof(t_philo) * data->philo_num);
    if(data->philo == NULL)
        return(print_error("malloc error\n"));
    i = 0;
    while(i < data->philo_num)
    {
        data->philo[i].num = i + 1;
        data->philo[i].start_time = 0;
        data->philo[i].l_fork = i;
        data->philo[i].r_fork = (i + 1); // (i + 1) % philo_num?
        data->philo[i].d = data;
        i++;
    }
    return(true);
}
//static bool init2()
bool    init(int ac, char **av, t_data *data)
{
    // *data = malloc(sizeof(t_data));
    // if(*data == NULL)
    //     return(print_error("malloc error\n"));
    if (ac == 6)
        data->op_eat_num = atooooi(av[5]);
    else
        data->op_eat_num = 0;
    data->philo_num = atooooi(av[1]);
    data->die_time = atooooi(av[2]);
    data->eat_time = atooooi(av[3]);
    data->sleep_time = atooooi(av[4]);
    if (!idx_check(data, ac)  || !philo_init(data))
    {
        god_free(data);
        return(false);
    }
    return(true);
}