NAME = containers

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror -std=gnu++0x -fsanitize=address

SRC = *.cpp\
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
re:	fclean all