NAME = ft_containers
CFLAGS = -fsanitize=address --std=c++98 -g -Wall -Wextra -Werror
SRCS = ${addprefix my_test/, ${shell ls tests | grep '\.cpp'}}
OBJS = ${SRCS:.cpp=.o}
CC = clang++
RM = rm -f
INC = -I./containers

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INC} ${OBJS} -o ${NAME}

%.o : %.cpp
	${CC} ${CFLAGS} ${INC} -c $< -o $@ -g

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
