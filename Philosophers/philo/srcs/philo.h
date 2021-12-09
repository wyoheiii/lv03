#ifndef  PHILO_H
# define PHILO_H

# define SUCCESS 1
# define FAILURE 0
#define TIME_MAX 1000
#define FORK 1
#define EAT 2
#define SLEEP 3
#define THINK 4
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include "struct.h"
bool    init(int ac,char **av,t_data *data);
bool av_check(int ac, char **av);
size_t	atooooi(const char	*str);
size_t	ft_strlen(const char	*s);
void god_free(t_data *data);
int print_error(char *error);
size_t get_time(void);
bool thread_main(t_data *data);
bool philo_eat_beefbowl(t_philo *philo);
bool philo_sleep(t_philo *philo);
bool philo_think(t_philo *philo);
void *eat_monitor(void *d);
void *dead_monitor(void *d);
#endif
