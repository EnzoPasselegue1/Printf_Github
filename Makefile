NAME = libftprintf.a
SRCS = ft_flags.c ft_numbers.c ft_printf.c ft_strings.c \
ft_utils.c ft_utils2.c main.c
OBJDIR = .obj/
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	ar -rcs $(OBJS) -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re 