CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = DiamondTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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

test:
	g++ -std=c++17 -isystem /opt/homebrew/include -pthread test.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp -L/opt/homebrew/lib -lgtest -lgtest_main -o test
	./test

re: fclean all

.PHONY: all clean fclean re test
