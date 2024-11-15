NAME = libftprintf.a
SRCS = ft_flags.c ft_numbers.c ft_printf.c ft_strings.c ft_utils.c ft_utils2.c

OBJDIR = .obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Werror -Wextra -Wall
AR = ar -rcs

$(OBJDIR)/%.o: %.c ft_printf.h Makefile
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re