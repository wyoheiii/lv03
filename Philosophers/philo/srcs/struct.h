#ifndef  STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_data t_data;
typedef struct s_philo
{
    int num;
    size_t start_time;
    int l_fork;
    int r_fork;
    pthread_t thread;
    t_data *d;

} t_philo;
typedef struct s_data
{
    int philo_num;
    int die_time;
    int eat_time;
    int sleep_time;
    int op_eat_num;
    int fork_num;
    t_philo *philo;
} t_data;

#endif