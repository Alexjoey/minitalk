SRC_CLIENT	= ./src/ft_client.c

SRC_SERVER	= ./src/ft_server.c

INCLUDES	= ./inc
CC			= cc

CFLAGS		= -g -Wall -Werror -Wextra 
INC_FLAGS	= -I$(INCLUDES) -L$(LIBFT_PATH) -lft
RM			= rm -f

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

NAME		= server client

all:		$(NAME)

$(LIBFT):	
			@make -s -C $(LIBFT_PATH)

server:	$(LIBFT)
				$(CC) $(CFLAGS) $(SRC_SERVER) $(INC_FLAGS) -o server 

client:	$(LIBFT)
				$(CC) $(CFLAGS) $(SRC_CLIENT) $(INC_FLAGS) -o client 
clean:
				@make -s clean -C $(LIBFT_PATH)
				@$(RM) $(OBJS)
fclean:		clean
				@make -s fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)
re:		
				@make fclean all
