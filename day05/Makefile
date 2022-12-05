NAME = a.out

CXX = c++

CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -MMD

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
