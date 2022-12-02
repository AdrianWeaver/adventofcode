NAME = a.out

CXX = c++

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CFLAGS) $^ -o $@

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean
		make all

test:	$(NAME)
		./$(NAME)

.PHONY: clean fclean re test
