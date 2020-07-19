##
## EPITECH PROJECT, 2020
## SYN_jetpack2Tek3_2019
## File description:
## Makefile
##

SERVER	=	serverJ2T3
CLIENT	=	clientJ2T3
GRAPH	=	graphJ2T3

S_SRC	=	src/server/main.c				\
			src/server/commands/finish.c 	\
			src/server/parsing/parsing.c 	\
			src/server/parsing/utils.c 		\
			src/server/sockets/server.c 	\
			src/server/sockets/sockets.c 	\
			src/server/sockets/connect.c 	\
			src/server/commands/map.c 		\
			src/server/utils/utilities.c 	\
			src/server/utils/utilities_con.c\
			src/server/commands/nooped_cmd.c
S_OBJ	=	$(S_SRC:.c=.o)

G_SRC	=	src/graphic/window.c			\
			src/graphic/animation.c			\
			src/graphic/manage.c			\
			src/graphic/main.c				\
			src/graphic/destroy.c
G_OBJ	=	$(G_SRC:.c=.o)

C_SRC	=	src/client/main.c				\
			src/client/errors.c				\
			src/client/loop.c				\
			src/client/utils/utilities.c	\
			src/client/utils/utilities_con.c\
			src/client/receive.c			\
			src/client/commands.c			\
			src/client/re_loop.c			\
			src/graphic/window.c			\
			src/graphic/animation.c			\
			src/graphic/manage.c			\
			src/graphic/destroy.c			\
			src/client/sending.c
C_OBJ	=	$(C_SRC:.c=.o)

INC	=	-Iinclude
LIB	=	-L .

CFLAGS	=	-W -Wall -Wextra -ggdb3 -g3
GFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

CC	=	gcc $(INC) $(CFLAGS)
GC	=	gcc $(INC) $(CFLAGS) $(GFLAGS)
RM	=	rm -f

all:	$(SERVER) $(CLIENT)
graph:	$(GRAPH)

$(SERVER)	:	$(S_OBJ)
	$(CC) $^ -o $@
$(GRAPH)	:	$(G_OBJ)
	$(GC) $^ -o $@
$(CLIENT)	:	$(C_OBJ)
	$(GC) $^ -o $@
%.o :	%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(S_OBJ)
	$(RM) $(G_OBJ)
	$(RM) $(C_OBJ)
fclean:	clean
	$(RM) $(SERVER)
	$(RM) $(GRAPH)
	$(RM) $(CLIENT)
re:	fclean all