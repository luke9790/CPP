CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp	Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Brainz

%.o: %.cpp
	$(CC) -c $(CFLAGS) $?

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean .c.o