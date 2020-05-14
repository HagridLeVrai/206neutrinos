##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for main.c
##

TARGET = 206neutrinos

CFLAGS  = -W -Wall -Wextra -lm

SRCS =	main.cpp	\
		values.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(CFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean re fclean
