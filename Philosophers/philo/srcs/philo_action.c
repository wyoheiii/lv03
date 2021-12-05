#include "philo.h"
// timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died


//bool philo_eat_beefbowl(t_philo *philo)
//{

//}
bool philo_sleep(t_philo *philo)
{
    size_t time;
    time = get_time();
    if(time == false)
        return(false);
    usleep(philo->d->sleep_time);
    printf("%ld %d is sleeping\n",time, philo->num);
    return(true);
}
bool philo_think(t_philo *philo)
{
    size_t time;
    time = get_time();
    if(time == false)
        return(false);
    //usleep();
    printf("%ld %d is thinking\n",time,philo->num);
    return(true);
}