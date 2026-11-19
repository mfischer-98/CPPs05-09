# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 13:12:06 by mefische          #+#    #+#              #
#    Updated: 2026/11/19 15:04:11 by mefische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/PresidentialPardonForm.cpp src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
CC  = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo  "$(LILAC)🎖️ Compilation finished $(RESET)"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(PINK)✨ Object files cleaned $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MINT)💫 All build files removed $(RESET)"

re: fclean all

.PHONY: all clean fclean re

# Colors
PINK  = \033[38;5;205m
MINT  = \033[38;5;121m
LILAC = \033[38;5;141m
RESET = \033[0m