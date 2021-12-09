/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:43:23 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/09 15:38:23 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int print_error(char *error)
{
    printf("%s", error);
    return (FAILURE);
}
void god_free(t_data *data)
{
    int i;
    while(i < data->philo_num)
    {
        pthread_mutex_destroy(&data->fork[i]);
        i++;
    }
    if(data->philo != NULL)
        free(data->philo);
    if(data->fork != NULL)
        free(data->fork);
    //free(*data);
}

