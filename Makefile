ERASE       		=    \033[2K\r
GREY        		=    \033[30m
RED            		=    \033[31m
GREEN        		=    \033[32m
YELLOW        		=    \033[33m
BLUE        		=    \033[34m
PINK        		=    \033[35m
CYAN        		=    \033[36m
WHITE       		=    \033[37m
BOLD       			=    \033[1m
UNDER       		=    \033[4m
SUR					=    \033[7m
END					=    \033[0m

NAME				=	vector

SRCS				=	main.cpp

OBJ_PATH			=	obj
OBJS				=	$(addprefix $(OBJ_PATH)/, $(SRCS:.cpp=.o))

INC_PATH			=	.
INCS				=	vector.hpp

CPPFLAG				=	-std=c++98
COMP				=	c++ $(CPPFLAG) -Wall -Wextra -Werror

RM					=	rm -rf

$(OBJ_PATH)/%.o		:	%.cpp $(INCS)
						@$(COMP) -c $< -o $@
						@printf "$(ERASE)$(YELLOW)$@\t-->\tCREATED\n$(END)"

all					:	init $(NAME)
init				:	
						@mkdir -p $(OBJ_PATH)

$(NAME)				:	$(OBJS)
						$(COMP) $(OBJS) -o $(NAME)
						@printf "$(ERASE)$(GREEN)$(NAME)\t\t-->\tCREATED\n$(END)"

clean				:
						@$(RM) $(OBJ_PATH)
						@printf "$(ERASE)$(GREEN)./$(OBJ_PATH)\t\t-->\tCLEANED\n$(END)"

fclean				:	clean
						@$(RM) $(NAME)

re					: 	fclean all

.PHONY: all clean fclean re