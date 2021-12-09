#include "philo.h"
void *eat_monitor(void *d)
{
    t_data *data;
    data = d;

    int cnt;
    int i;
    while(!data->end_flag)
    {
        
        i = 0;
        cnt = 0;
        while(i < data->philo_num)
        {
            if(data->philo[i].eat_count >= data->max_eat_num)
                cnt++;
            if(cnt == data->philo_num)
            {
                data->end_flag = 1;
                break;
            }
            i++;
        }
    }
    return(NULL);
} 
void *dead_monitor(void *d)
{
    t_data *data;
    //size_t time;
    data = (t_data *)d;

    int i;

    while(!data->end_flag)
    {
        i = 0;
        while(i < data->philo_num)
        {
            if ((get_time() - data->philo[i].last_eat_time) >= data->die_time)
            {
                data->end_flag = 1;
                printf("%ld %d died\n",get_time(), data->philo[i].num);
                break;
            }
            i++;
        }
    }
    return(NULL);
}