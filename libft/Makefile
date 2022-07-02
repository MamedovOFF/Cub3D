# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 15:31:36 by jchopped          #+#    #+#              #
#    Updated: 2022/05/08 13:27:27 by jchopped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a 

SRCS		=	ft_isdigit.c ft_isalpha.c ft_isprint.c\
				ft_isascii.c ft_isalnum.c ft_memset.c\
				ft_bzero.c ft_memcpy.c ft_memmove.c\
				ft_strlcat.c ft_strlcpy.c ft_toupper.c\
				ft_tolower.c ft_strchr.c ft_strrchr.c\
				ft_strlen.c ft_strncmp.c ft_memchr.c\
				ft_memcmp.c ft_strnstr.c ft_atoi.c\
				ft_calloc.c ft_strdup.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c\
				ft_putnbr_fd.c ft_striteri.c\
				ft_lstnew.c ft_lstlast.c ft_lstadd_front.c\
				ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADER		=	libft.h
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(SRCS_B:%.c=%.o)
 
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus		:
	@make OBJS="$(OBJS_B)" all

clean		:	
	@rm -f $(OBJS) $(OBJS_B)

fclean		:	clean
	@rm -f $(NAME)

re:			fclean all
