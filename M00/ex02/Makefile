CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account

SRC = Account.cpp tests.cpp
OBJS = $(SRC:.cpp=.o)

RM = rm -rf

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
