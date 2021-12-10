SRCS = main.c util.c av_check.c philo_init.c pthread_main.c \
		philo_action.c monitor.c
SRCSD = ./srcs/

ADDSRCS = $(addprefix $(SRCSD),$(SRCS))
OBJS		=   $(ADDSRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror #-I. #-fsanitize=address #-fsanitize=thread
PFLAGS			= -g -pthread
NAME			= philo
#-fsanitize=thread
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(PFLAGS) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re