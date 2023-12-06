CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

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