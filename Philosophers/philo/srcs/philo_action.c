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

    pthread_mutex_lock(&p->d->common_protect);
    if (!p->d->end_flag)
    {
        if (action == FORK)
            printf("%ld %d has taken a fork\n",get_time(),p->num);
        else if (action == EAT)
        {
            printf("%ld %d is eating\n",get_time(),p->num);
            p->last_eat_time = get_time();
            p->eat_count++;
            // printf("eat_count :%d\n",);
            // printf("max_eat_num :%d\n",);
            // printf("philo_num :%d\n",);
            //  printf("philo_eat_count :%d\n",p->);
            if(p->eat_count == p->d->max_eat_num)
            {
                p->d->philos_eat_count++;
                if(p->d->philos_eat_count == p->d->philo_num)
                   p->d->end_flag = 1;
            }
        }
        else if (action == SLEEP)
            printf("%ld %d is sleeping\n",get_time(), p->num);
        else if (action == THINK)
            printf("%ld %d is thinking\n",get_time(), p->num);
        pthread_mutex_unlock(&p->d->common_protect);
        return(true);
    }
    pthread_mutex_unlock(&p->d->common_protect);
    return(false);
}

// bool philo_eat_beefbowl(t_philo *p)
// {
//     if(!p->d->end_flag)
//         pthread_mutex_lock(&p->d->fork[p->r_fork]);
//     if(!print_action(p, FORK))
//         return (false);
//     if(!p->d->end_flag)
//         pthread_mutex_lock(&p->d->fork[p->l_fork]);
//     if(!print_action(p, FORK))
//         return (false);
//     if(!print_action(p, EAT))
//         return(false);
//     if(!p->d->end_flag)
//         usleep(p->d->eat_time);
//     if(!p->d->end_flag)
//         pthread_mutex_unlock(&p->d->fork[p->r_fork]);
//     if(!p->d->end_flag)
//         pthread_mutex_unlock(&p->d->fork[p->l_fork]);
    
//     return(true);
// }
static void one_philo(t_philo *p)
{
    pthread_mutex_lock(&p->d->fork[p->r_fork]);
    if(!print_action(p, FORK))
        return ;
    while(!p->d->end_flag)
        usleep(100);
}
bool philo_eat_beefbowl(t_philo *p)
{
    if (p->d->philo_num == 1)
    {
        one_philo(p);
        return(false);
    }
    pthread_mutex_lock(&p->d->fork[p->r_fork]);
    print_action(p, FORK);
    pthread_mutex_lock(&p->d->fork[p->l_fork]);
    print_action(p, FORK);
    print_action(p, EAT);
    while((get_time() - p->last_eat_time) <= p->d->eat_time && !p->d->end_flag)
        usleep(100);
    pthread_mutex_unlock(&p->d->fork[p->r_fork]);
    pthread_mutex_unlock(&p->d->fork[p->l_fork]);
    return(true);
}
bool philo_sleep(t_philo    *p)
{
    size_t sleep;

    if (!print_action(p, SLEEP))
        return(false);
    sleep = get_time();
    while((get_time() - sleep) <= p->d->sleep_time && !p->d->end_flag)
        usleep(100);
    return(true);
}

bool philo_think(t_philo *philo)
{
    if (!print_action(philo, THINK))
        return(false);
    usleep(100);
    return(true);
}
