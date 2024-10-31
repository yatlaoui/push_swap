# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:11:48 by yaatlaou          #+#    #+#              #
#    Updated: 2024/10/31 22:06:49 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Dossier et nom de la bibliothèque libft (si elle est utilisée)
LIB_PATH = libft
LIB_NAME = libft.a
LIB = $(LIB_PATH)/$(LIB_NAME)

# Inclusion de libft (si besoin)
# INCLUDES = -I $(LIB)

SOURCES = push_swap.c \
          index.c \
		  main.c \
          init_struct.c \
          mini_algo.c \
          op_push.c \
          op_r_rotate.c \
          op_rotate.c \
          op_swap.c \
          parsing.c \

# object directory
OBJDIR = obj

# Fichiers objets générés à partir des sources
OBJ = $(SOURCES:%.c=$(OBJDIR)/%.o)

# Lien avec la bibliothèque libft (si elle est utilisée)
# LIBS = $(LIB_PATH) -l:libft.a

# Règle par défaut : compilation de l'exécutable
all: $(LIB) $(NAME)

# Compilation de la libft si elle existe (sinon, omettre cette partie)
$(LIB):
	@$(MAKE) -C $(LIB_PATH)

# Compilation de l'exécutable push_swap
$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -l:libft.a -o $(NAME)

# Règle pour compiler les fichiers objets
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIB_PATH) clean

# Nettoyage complet : fichiers objets et exécutable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
