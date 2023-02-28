SRCS			= fractol.c hooks_do.c creat_Mandelbrot.c creat_julian.c \
					creat_fract.c clos_and_free.c fractol_util.c \
					check_arg_julian.c check_argv.c ft_split.c ft_libs.c get_instru_and_ret.c

OBJS			= $(SRCS:.c=.o)

BONUS			= fractol_bonus.c hooks_do_bonus.c creat_Mandelbrot_bonus.c creat_julian_bonus.c \
					creat_fract_bonus.c clos_and_free_bonus.c fractol_util_bonus.c creat_Burning_bonus.c \
					check_arg_julian_bonus.c check_argv_bonus.c ft_split_bonus.c ft_libs_bonus.c \
					get_instru_and_ret_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= fractol

BONUS_NAME		= fractol_bonus

all:			$(OBJS) $(NAME) fractol.h Makefile

$(NAME):		$(OBJS) fractol.h Makefile
				$(CC) $(CFLAGS) $(OBJS) libmlx.dylib -o $(NAME)

$(OBJS):		fractol.h Makefile

$(BONUS_OBJS):	fractol_bonus.h Makefile

clean:
				$(RM) $(OBJS)

clean_bonus:
				$(RM) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

fclean_bonus:	clean_bonus
				$(RM) $(BONUS_NAME)

re:				fclean $(NAME)

re_bonus:		fclean_bonus $(BONUS_NAME)

bonus:			$(BONUS_OBJS) $(BONUS_NAME) fractol_bonus.h Makefile

$(BONUS_NAME):	$(BONUS_OBJS) fractol_bonus.h Makefile
				$(CC) $(BONUS_OBJS) libmlx.dylib -o $(BONUS_NAME)

.PHONY:			all clean fclean re bonus clean_bonus fclean_bonus re_bonus