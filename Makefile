SRCS			= fractol.c hooks_do.c creat_Mandelbrot.c creat_julian.c \
					creat_fract.c clos_and_free.c fractol_util.c creat_Burning_bonus.c \
					check_arg_julian.c check_argv.c ft_split.c ft_libs.c

OBJS			= $(SRCS:.c=.o)

#BONUS			= 

#BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= fractol

#BONUS_NAME		= checker

all:			$(OBJS) $(NAME) fractol.h Makefile

$(NAME):		$(OBJS) fractol.h
				$(CC) $(CFLAGS) $(OBJS) libmlx.dylib -o $(NAME)

$(OBJS):		fractol.h

clean:
				$(RM) $(OBJS) 
#$(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) 
#$(BONUS_NAME)

re:				fclean $(NAME) 
##$(BONUS_NAME)

bonus:			$(BONUS_OBJS) $(BONUS_NAME)

#$(BONUS_NAME):	$(BONUS_OBJS) Makefile
#				$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY:			all clean fclean re