##
## Makefile for My IRC in /home/meiche_j/rendu/PSU_2015_myirc
## 
## Made by Jean-Malo
## Login   <meiche_j@epitech.net>
## 
## Started on  Tue May 17 15:52:37 2016 Jean-Malo
## Last update Mon Oct 17 14:58:27 2016 Jean-Malo
##

SRCS = main.cpp \
	sha256.cpp \
	user.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = logger

CFLAGS = -W -Wall -Wextra

LD_FLAGS = 

MAKE = make

CXX = clang++

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) -o $(NAME) $(OBJS) $(LD_FLAGS)

clear: 
	clear;clear;clear

clean:
	@rm -vf $(OBJS)

fclean: clean
	@rm -vf $(NAME)

re: fclean all

rec: clear fclean all
	@rm -vf $(OBJS)

debug:
	@$(CXX) -o $(NAME_SRV) $(SRCS_SRV) $(CFLAGS) $(LD_FLAGS) -g
	@$(CXX) -o $(NAME_CLI) $(SRCS_CLI) $(CFLAGS) $(LD_FLAGS) -g

