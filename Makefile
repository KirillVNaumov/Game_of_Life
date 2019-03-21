# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 22:08:06 by knaumov           #+#    #+#              #
#    Updated: 2019/02/25 13:28:26 by amelikia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I includes

SRCS = 	srcs/main.cpp \
		srcs/utils.cpp \
		srcs/apply_changes.cpp \
		srcs/parse_args/parse_args.cpp \
		srcs/parse_args/read_file.cpp \
		srcs/parse_args/read_size.cpp \
		srcs/parse_args/read_speed.cpp \
		srcs/read_from_file/map_from_char_to_int.cpp \
		srcs/read_from_file/read_from_file.cpp \
		srcs/simulation_no_graphics/draw_map_no_graphics.cpp \
		srcs/simulation_no_graphics/run_simulation_no_graphics.cpp

OBJ	=	$(SRCS:.cpp=.o)

EXEC = exe

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.cpp
			@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
			@clang++ -c $< -o $@ $(INCLUDES) -g

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@clang++ -o $(EXEC) $(OBJ) $(INCLUDES) $(INCLUDES) -g
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all

.PHONY: clean fclean re
