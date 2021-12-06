#ifndef  STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_data t_data;
typedef struct s_philo
{
    size_t eat_count;
    size_t num;
    size_t start_time;
    size_t l_fork;
    size_t r_fork;
    size_t last_eat_time;
    int    action_flag;
    pthread_t thread;
    t_data *d;

} t_philo;
typedef struct s_data
{
    size_t philo_num;
    size_t die_time;
    size_t eat_time;
    size_t sleep_time;
    size_t max_eat_num;
    size_t fork_num;
    pthread_mutex_t *fork;
    t_philo *philo;
} t_data;

#endif