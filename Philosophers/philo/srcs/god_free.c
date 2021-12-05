/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabeyouhei <watanabeyouhei@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:43:23 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/05 15:36:28 by watanabeyou      ###   ########.fr       */
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
    if(data->philo != NULL)
        free(data->philo);
    //free(*data);
    
}

