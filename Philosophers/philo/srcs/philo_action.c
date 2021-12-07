#include "philo.h"
//   timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
//      59ms以下は弾く 3 299 100 100 1
//死ぬのをモニターで管理
bool philo_eat_beefbowl(t_philo *p)
{
    size_t time;

    
    pthread_mutex_lock(&p->d->fork[p->l_fork]);
    //printf("&p->d->fork[p->l_fork]  :%d\n",p->l_fork);
    time = get_time();
    printf("%ld %d has taken a fork\n",time,p->num);
    //printf("&p->d->fork[p->r_fork]  :%d\n",p->r_fork);
    pthread_mutex_lock(&p->d->fork[p->r_fork]);
    time = get_time();
    printf("%ld %d has taken a fork\n",time,p->num);
    time = get_time();
    printf("%ld %d is eating\n",time,p->num);
    usleep(p->d->eat_time);
    pthread_mutex_unlock(&p->d->fork[p->l_fork]);
    pthread_mutex_unlock(&p->d->fork[p->r_fork]);
    p->eat_count++;
    return(true);
}
bool philo_sleep(t_philo    *philo)
{
    size_t time;
    time = get_time();
    if(time == false)
        return(false);
    printf("%ld %d is sleeping\n",time, philo->num);
    usleep(philo->d->sleep_time);
    return(true);
}

bool philo_think(t_philo *philo)
{
    size_t time;

    time = get_time();
    printf("%ld %d is thinking\n",time,philo->num);
    usleep(100);
    return(true);
}
