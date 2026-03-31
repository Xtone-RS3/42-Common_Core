NAME = codexion

SOURCES = codexion.c\
	arg_stuff.c\
	death_n_dongles.c\
	edf.c\
	heap_n_fifo.c\
	init_one.c\
	init_two.c\
	routine.c\
	utils.c

FLAGS = -Wall -Wextra -Werror -pthread

$(NAME): $(SOURCES)
	cc $(SOURCES) -o $(NAME) $(FLAGS)

all: $(NAME)

clean:
	rm -f $(SOURCES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re