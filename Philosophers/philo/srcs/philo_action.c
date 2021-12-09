#include "philo.h"
//   timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
//   59ms以下は弾く 3 299 100 100 1
//死ぬのをモニターで管理

bool print_action(t_philo *p, int  action)
{
    size_t time ;
    
    if (!p->d->end_flag)
    {
        time = get_time();
        if (action == FORK)
             printf("%ld %d has taken a fork\n",time,p->num);
        else if (action == EAT)
        {
            printf("%ld %d is eating\n",time,p->num);
            p->last_eat_time = time;
            p->eat_count++;
        }
        else if (action == SLEEP)
            printf("%ld %d is sleeping\n",time, p->num);
        else if (action == THINK)
            printf("%ld %d is thinking\n",time, p->num);
        return(true);
    }
    return(false);
}

bool philo_eat_beefbowl(t_philo *p)
{
    pthread_mutex_lock(&p->d->fork[p->r_fork]);
    if(!print_action(p, FORK))
        return (false);
    pthread_mutex_lock(&p->d->fork[p->l_fork]);
    if(!print_action(p, FORK))
        return (false);
    if(!print_action(p,EAT))
        return(false);
    usleep(p->d->eat_time);
    pthread_mutex_unlock(&p->d->fork[p->r_fork]);
    pthread_mutex_unlock(&p->d->fork[p->l_fork]);
    
    return(true);
}
bool philo_sleep(t_philo    *philo)
{
    if (!print_action(philo, SLEEP))
        return(false);
    usleep(philo->d->sleep_time);
    return(true);
}

bool philo_think(t_philo *philo)
{
    if (!print_action(philo, THINK))
        return(false);
    usleep(1000);
    return(true);
}
