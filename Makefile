NAMEC = client
NAMES = server

BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus

PRINTF = libftprintf.a

SRCC = client.c
SRCS = server.c

BONUSC= client_bonus.c
BONUSS= server_bonus.c

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
	@make -C printf
	$(CC) $(CFLAGS) $(OBJC) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) printf/$(PRINTF) -o $(NAMES)

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
	@make -C printf
	$(CC) $(CFLAGS) $(OBJBC) printf/$(PRINTF) -o $(BONUS_NAMEC)

$(BONUS_NAMES) : $(OBJBS)
	$(CC) $(CFLAGS) $(OBJBS) printf/$(PRINTF) -o $(BONUS_NAMES)

clean :
	@make clean -C printf
	${RM} ${OBJC}
	${RM} ${OBJS}
	${RM} ${OBJBC}
	${RM} ${OBJBS}

fclean : clean
	@make fclean -C printf
	${RM} $(NAMEC)
	${RM} $(NAMES)
	${RM} $(BONUS_NAMEC)
	${RM} $(BONUS_NAMES)
	${RM} $(PRINTF)

re : fclean all

.PHONY: all bonus clean fclean re
