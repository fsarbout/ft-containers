NAME = ft_containers

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=gnu++0x -std=c++98 -g #-fsanitize=address

# SRC = tests/_map.cpp\

SRC = tests/_stack.cpp\

# SRC = tests/_vector.cpp\
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
re:	fclean all