CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Serialization

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean .c.o
