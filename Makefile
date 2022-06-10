##
## EPITECH PROJECT, 2021
## <DON'T FORGET TO PUT PROJECT NAME HERE!!!!>
## File description:
## Makefile
##

## Variable to be modified
rm = rm -rf

TARGET = MineSweeper

CFLAGS = -Wextra -Wall -Iinclude

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -I./include/
SRC	=	sweeper_main.cpp

OBJ	=	$(SRC:.c=.o)

all:	$(TARGET)

%.o: %.c
	&& printf "[\033[1;35mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m] % 29s\n" $< |  tr ' ' '.'

$(TARGET): $(OBJ)
	g++ $(OBJ) -o $(TARGET) $(LDFLAGS)
	@echo -e "\e[1;36mFinished compiling $@\e[0m"

clean:
	@$(rm) $(OBJ)
	@echo "Removed .o files"

fclean: clean
	@$(rm) $(TARGET)
	@echo "Removed binary file"

re: fclean all
