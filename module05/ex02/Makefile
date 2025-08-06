NAME = Bureaucrat_Advanced_Form

HEADERS = $(wildcard *.hpp)
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re