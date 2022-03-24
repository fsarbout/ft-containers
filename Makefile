NAME = Vector

CC = c++

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c++98

SRC = *.cpp\
	Vector/*.cpp\
	Iterators/*.cpp\
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) 
re:	fclean all