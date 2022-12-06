NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -g3

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CFLAGS) $^ -o $@

clean:
		rm -rf $(OBJS)
		rm -rf $(DEPS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean
		make all

test:	$(NAME)
		./$(NAME)

.PHONY: clean fclean re test
