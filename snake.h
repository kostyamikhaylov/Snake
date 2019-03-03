#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define SLEEP 500000
#define LINES 15
#define WIDTH 25

static char arr[LINES][WIDTH];

struct point
{
	int line;
	int column;
};

struct list
{
	struct point position;
	struct list *next;
};

struct snake
{
	int direction;
	struct list *s;
};

void Draw (struct snake *s);
void FreeSnake (struct snake *s);
void FreeTail (struct snake *s);

