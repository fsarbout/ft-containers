NAME = ft_containers

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=gnu++0x -std=c++98 -g

SRC = map/map_test.cpp\
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
re:	fclean all