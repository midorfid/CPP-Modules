NAME = Account

LOG = build.log

SRC = tests.cpp Account.cpp

CC = -c++ -Wall -Wextra -Werror -std=c++98

$(shell echo "" > $(LOG))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME) >> $(LOG) 2>&1

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all