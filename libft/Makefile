SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c is_empty.c\
ft_str_tolower.c ft_strccpy.c ft_strset.c ft_strrset.c ft_strcmp.c

BONUS = ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c\
 ft_lstadd_back.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
BONOBJ = ${BONUS:.c=.o}
LIBS = ar rcs
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@
	
bonus: $(NAME) $(BONOBJ)
	$(LIBS) $(NAME) $(BONOBJ)

clean:
	rm -f $(OBJ) $(BONOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
