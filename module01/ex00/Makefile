NAME = Zombie

SRC = Zombie.cpp randomChump.cpp newZombie.cpp main.cpp

CC = -c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all