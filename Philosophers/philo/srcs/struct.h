#ifndef  STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_data t_data;
typedef struct s_philo
{
    int eat_count;
    int num;
    size_t start_time;
    int l_fork;
    int r_fork;
    size_t last_eat_time;
    //int    action_flag;
    pthread_t thread;
    //pthread_mutex_t l_fork;
    //pthread_mutex_t r_fork;
    t_data *d;

} t_philo;
typedef struct s_data
{
    int philo_num;
    size_t die_time;
    size_t eat_time;
    size_t sleep_time;
    int max_eat_num;
    int fork_num;
    pthread_mutex_t *fork;
    t_philo *philo;
} t_data;

#endif