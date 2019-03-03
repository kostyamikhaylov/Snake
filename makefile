TAG = snake
HDR = snake.h
DEP1 = snake
DEP2 = draw
DEP3 = free_snake
DEPS = $(DEP1).o $(DEP2).o $(DEP3).o
CC = gcc

$(TAG): $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

$(DEPS): $(HDR)

clean:
	rm -f $(DEPS)

