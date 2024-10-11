NAME = philo

CFLAGS = -Wall -Wextra -Werror -g -O0

RM = rm -rf

SRCS = 	$(wildcard ./src/*.c)

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME) -lpthread

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all