/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:52:41 by wyohei            #+#    #+#             */
/*   Updated: 2021/12/04 22:50:33 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//ac avチェック マイナスか
//av[1]哲学者数=フォーク数 
//av[2] 死ぬまでの時間(ms) 1ms 0.001 食事開始時間orシミュレーション開始時間
//av[3]食事する時間(ms)  
//av[4]睡眠する時間(ms)
//av[5]プログラムを終了する食事回数
int main (int ac, char **av)
{
    t_data *data;
    
    if(ac == 5 || ac == 6)
    {
        if (!av_check(ac, av))
            return (FAILURE);
        if (!init(ac, av, &data))
            return (FAILURE);
        if ()
        return(SUCCESS);
    }
    //god_free(&data);
    return(print_error("ac_error\n"));
}