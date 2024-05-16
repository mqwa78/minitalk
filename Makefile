SRC_C		=	./src/client.c
SRC_S		=	./src/server.c
SRC_C_BNS	=	./bonus/client_bonus.c
SRC_S_BNS	=	./bonus/server_bonus.c
OBJ_C		=	$(SRC_C:.c=.o)
OBJ_S		=	$(SRC_S:.c=.o)
OBJ_C_BNS	=	$(SRC_C_BNS:.c=.o)
OBJ_S_BNS	=	$(SRC_S_BNS:.c=.o)
NAME_C		=	client
NAME_S		=	server
NAME_C_BNS	=	client_bonus
NAME_S_BNS	=	server_bonus
PRINTF		=	libftprintf.a
CC			=	cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -I include

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
		@make -C printf
		$(CC) $(OBJ_C) $(CFLAGS) printf/$(PRINTF) -o $(NAME_C)

$(NAME_S) : $(OBJ_S)
		@make -C printf
		$(CC) $(OBJ_S) $(CFLAGS) printf/$(PRINTF) -o $(NAME_S)

bonus : $(NAME_C_BNS) $(NAME_S_BNS)

$(NAME_C_BNS) : $(OBJ_C_BNS)
		@make -C printf
		$(CC) $(OBJ_C_BNS) $(CFLAGS) printf/$(PRINTF) -o $(NAME_C_BNS)

$(NAME_S_BNS) : $(OBJ_S_BNS)
		@make -C printf
		$(CC) $(OBJ_S_BNS) $(CFLAGS) printf/$(PRINTF) -o $(NAME_S_BNS)

clean :
	@make clean -C printf
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_C_BNS) $(OBJ_S_BNS)

fclean : clean
	@make fclean -C printf
	rm -rf $(NAME_C) $(NAME_S) $(NAME_C_BNS) $(NAME_S_BNS) $(PRINTF)

re : fclean all

.PHONY : all clean fclean re