SRCS		= 
OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra -I$(LIBFT_PATH)

RM			= rm -f

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

NAME		= ft_server ft_client

all:		$(NAME)

$(LIBFT):	
			make -C $(LIBFT_PATH)

$(NAME):	$(OBJS) $(LIBFT)
				ar rcs $(NAME) $(OBJS)
clean:
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)
fclean:		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)
re:		
				make fclean all
