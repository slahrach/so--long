NAME = so_long

LIB = libft/libft.a

LIBFT = ./libft

SRCS =  main.c read_map.c check_map.c errors_messages.c file_to_img.c put_map.c move.c move_utils.c

CFLAGS = -Wall -Wextra -Werror

CLINKS = -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	Make -C ${LIBFT}
	${CC} -o ${NAME} ${OBJS} ${LIB} ${CLINKS}

clean :
	Make clean -C ${LIBFT}
	rm -f ${OBJS}

fclean : clean
	Make fclean -C ${LIBFT}
	rm -f ${NAME}

re : fclean all

%.o : %.c
	${CC} ${CFLAGS} -c $<

.PHONY: clean all fclean re bonus
