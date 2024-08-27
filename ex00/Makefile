NAME = easyfind
FLAGS = -Wall -Werror -Wextra -std=c++98 -g
CC = c++
RM = rm -rf

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
