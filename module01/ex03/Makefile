NAME = gunz

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CC = -c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all