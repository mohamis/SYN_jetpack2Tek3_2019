##
## EPITECH PROJECT, 2020
## SYN_jetpack2Tek3_2019
## File description:
## Makefile
##

SERVER	=	serverJ2T3
CLIENT	=	clientJ2T3

S_SRC	=	src/server/main.c	\
			src/server/core.c
S_OBJ	=	$(S_SRC:.c=.o)

C_SRC	=	src/client/main.c	\
			src/client/core.c
C_OBJ	=	$(C_SRC:.c=.o)

INC	=	-Iinclude
LIB	=	-L .

CFLAGS	=	-W -Wall -Wextra -ggdb3 -g3

CC	=	gcc $(INC) $(LIB) $(CFLAGS)
RM	=	rm -f

all:	$(SERVER)

$(SERVER)	:	$(S_OBJ)
	$(CC) $^ -o $@
$(CLIENT)	:	$(C_OBJ)
	$(CC) $^ -o $@
%.o :	%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)
fclean:	clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
re:	fclean all