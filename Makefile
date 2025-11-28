# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 23:03:47 by nsongsit          #+#    #+#              #
#    Updated: 2025/11/28 23:05:41 by nsongsit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft

LIBFT_A		= libft.a
LIBMEM_A	= libmemtracker.a
LIBFD_A		= libfdtracker.a

LIBFT_DIR	= libft
LIBFT_SRC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
				ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

LIBFT_SRCS	= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC))
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

MEM_SRCS	= mem_free_all.c mem_free_partial.c mem_perror.c \
				mem_register.c mem_storage.c
MEM_OBJS	= $(MEM_SRCS:.c=.o)

FD_SRCS		= fd_close_all.c fd_close_partial.c fd_perror.c \
				fd_register.c fd_storage.c
FD_OBJS		= $(FD_SRCS:.c=.o)

PIPEX_SRCS	= pipex.c pipex_exec.c pipex_process.c pipex_utils.c
PIPEX_OBJS	= $(PIPEX_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT_A) $(LIBMEM_A) $(LIBFD_A) $(PIPEX_OBJS)
	$(CC) $(CFLAGS) $(PIPEX_OBJS) -L. -lmemtracker -lfdtracker -lft -o $(NAME)

$(LIBFT_A): $(LIBFT_OBJS)
	ar rcs $(LIBFT_A) $(LIBFT_OBJS)

$(LIBMEM_A): $(MEM_OBJS)
	ar rcs $(LIBMEM_A) $(MEM_OBJS)

$(LIBFD_A): $(FD_OBJS)
	ar rcs $(LIBFD_A) $(FD_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(LIBFT_OBJS) $(MEM_OBJS) $(FD_OBJS) $(PIPEX_OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBFT_A) $(LIBMEM_A) $(LIBFD_A)

re: fclean all

.PHONY: all clean fclean re
