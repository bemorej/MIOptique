RM = /bin/rm -f
CC = gcc
CXX = g++
#CFLAGS = -std=c99 -W -Wall -Wextra -pedantic #option compilateur
# pour tgmath.h ou math.h
CFLAGS = -std=c99 -lm -W -Wall -Wextra -pedantic

# sources ---- lignes a editer ---- #
MAIN = relai_ying.c	# << Programme principal
# --------------------------------- #
OBJS_MAIN = $(MAIN:.c=.o)
EXEC = $(MAIN:.c=)

$(EXEC) : $(OBJS_MAIN)
	$(CC) $(OBJS_MAIN) $(CFLAGS) -o $@
	
$(OBJS_MAIN) : $(MAIN)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	$(RM) $(EXEC) *.o

run: $(EXEC)
	./$(EXEC)
