#include "philo.h"
static bool check_eat_count(t_philo *philo)
{
    int i;
    int cnt;
    i = 0;
    cnt = 0;
    while(i < philo->d->philo_num)
    {
        if(philo->d->philo[i].eat_count >= philo->d->max_eat_num)
        {
            cnt++;
            if (cnt == philo->d->max_eat_num)
                return(false);
        }
        i++;
    }
    return (true);
}
// static bool check_eat_count(t_philo *philo)
// {
//     if (philo->eat_count == philo->d->max_eat_num)
//         return (false);
//     return(true);
// }

void *philo_table(void *p)
{
    //飯　死ぬ　寝る　考える　ゲットタイムつける
    t_philo *philo;
    philo = p;
    //printf("philo_num%ld\n",philo->num);
    if((philo->start_time = get_time()) == false)
        return(NULL);
    if (philo->num % 2 == 0)
        usleep(philo->d->eat_time);
    while(1)
    {
        if(!philo_eat_beefbowl(philo))
            break;
        if(!check_eat_count(philo))
            break;
        if(!philo_sleep(philo))
            break;
         if(!philo_think(philo))
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
    j = 0;
    while(j < data->philo_num)
    {

        if(pthread_join(data->philo[j].thread, NULL) != 0)
            return(print_error("join error\n"));
        j++;
    }
    printf("threadowari\n");
    return (true);
}