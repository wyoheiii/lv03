#ifndef  PHILO_H
# define PHILO_H

# define SUCCESS 1
# define FAILURE 0

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include "struct.h"
bool    init(int ac,char **av,t_data **data);
bool av_check(int ac, char **av);
int	atooooi(const char	*str);
size_t	ft_strlen(const char	*s);
void god_free(t_data **data);
int print_error(char *error);
#endif
