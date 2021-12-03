/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:43:23 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/03 15:37:18 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int print_error(char *error)
{
    printf("%s", error);
    return (FAILURE);
}
void god_free(t_data **data)
{
    //if((*data)->philo != NULL)
    //    free((*data)->philo);
    free(*data);
    
}

