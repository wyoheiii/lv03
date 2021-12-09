#include "philo.h"
// static bool check_eat_count(t_philo *philo)
// {
//     int i;
//     int cnt;
//     i = 0;
//     cnt = 0;
//     while(i < philo->d->philo_num)
//     {
//         if(philo->d->philo[i].eat_count >= philo->d->max_eat_num)
//         {
//             cnt++;
//             if (cnt == philo->d->max_eat_num)
//                 return(false);
//         }
//         i++;
//     }
//     return (true);
// }
// static bool check_eat_count(t_philo *philo)
// {
//     if (philo->eat_count == philo->d->max_eat_num)
//         return (false);
//     return(true);
// }

void *philo_table(void *p)
{
    //mutexで競合しないようにする.
    //飯　死ぬ　寝る　考える　ゲットタイムつける
    t_philo *philo;
    philo = p;
    philo->last_eat_time = get_time();
    if (philo->num % 2 == 0)
        usleep(philo->d->eat_time -100);
    while(1)
    {
        if(philo->d->end_flag || !philo_eat_beefbowl(philo))
            break;
        if(philo->d->end_flag || !philo_sleep(philo))
            break;
         if(philo->d->end_flag||!philo_think(philo))
            break;
    }
    return (NULL);
}
bool thread_main(t_data *data)
{
    int i;
    int j;
    i = 0;
    
    while(i < data->philo_num)
    {
        if(pthread_create(&data->philo[i].thread, NULL, &philo_table, &data->philo[i]) != 0)
            return(print_error("create error\n"));
        i++;
    }

    if(pthread_create(&data->count_eat_monitor, NULL, &eat_monitor, data) != 0)
        return(print_error("create error\n"));
    if(pthread_create(&data->starvation_monitor, NULL, &dead_monitor, data) != 0)
        return(print_error("create error\n"));
    j = 0;
    while(j < data->philo_num)
    {

        if(pthread_join(data->philo[j].thread, NULL) != 0)
            return(print_error("join error\n"));
        j++;
    }
    if(pthread_join(data->count_eat_monitor, NULL) != 0)
            return(print_error("join error\n"));
    if(pthread_join(data->starvation_monitor, NULL) != 0)
            return(print_error("join error\n"));
    return (true);
}