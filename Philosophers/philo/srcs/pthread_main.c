#include "philo.h"
bool check_eat_count(t_philo *philo)
{
    size_T i;
    i = 0;
    while(i < philo->d->philo_num)
    {
        if(philo)
    }
}
void *philo_table(void *p)
{
    //飯　死ぬ　寝る　考える　ゲットタイムつける
    t_philo *philo;
    philo = p;
    printf("philo_num%d\n",philo->num);
    if((philo->start_time = get_time()) == false)
        return(NULL);
    while(1)
    {
        //if(!philo_eat_beefbowl(philo))
        //    break;
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
    size_t i;
    i = 0;
    
    while(i < data->philo_num)
    {
        if(pthread_create(&data->philo[i].thread, NULL, &philo_table, &data->philo[i]) != 0)
            return(print_error("create error\n"));
        i++;
    }
    i = 0;
    while(i < data->philo_num)
    {
        if(pthread_join(data->philo[i].thread, NULL) != 0)
            return(print_error("join error\n"));
        i++;
    }
    return (true);
}