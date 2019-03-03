#include "snake.h"

struct snake s;

void handlerQUIT (int signal)
{
	if (s.direction == 4)
		s.direction = 1;
	else
		s.direction = s.direction + 1;
}

void handlerINT (int signal)
{
	FreeSnake (&s);
	exit (EXIT_SUCCESS);
}

struct list *CreateElem (int line, int column)
{
	struct list *new = (struct list *) calloc (1, sizeof (*new));
	new->position.line = line;
	new->position.column = column;
	new->next = NULL;

	return new;
}

void Move (struct snake *s)
{
	int line 	= 	s->s->position.line,
		column 	= 	s->s->position.column;

	switch (s->direction)
	{
		case 1:
			line = (line > 0) ? (line - 1) % LINES : LINES - 1;
			break;
		case 2:
			column = (column + 1) % WIDTH;
			break;
		case 3:
			line = (line + 1) % LINES;
			break;
		case 4:
			column = (column > 0) ? (column - 1) % WIDTH : WIDTH - 1;
			break;
		default:
			printf ("Wrong\n");
			return ;
			break;
	}
	
	struct list *l = CreateElem (line, column);

	l->next = s->s;
	s->s = l;

	FreeTail (s);

	return ;
}

void Step (struct snake *s)
{
	Draw (s);
	Move (s);
}

int main ()
{
	s.direction = 4;
	s.s = CreateElem (7, 14);
	s.s->next = CreateElem (7, 15);
	s.s->next->next = CreateElem (7, 16);
	s.s->next->next->next = CreateElem (8, 16);
	s.s->next->next->next->next = CreateElem (9, 16);
	s.s->next->next->next->next->next = CreateElem (10, 16);

	signal (SIGQUIT, handlerQUIT);
	signal (SIGINT, handlerINT);

	while (1)
	{
		usleep (SLEEP);
		Step (&s);
	}

	return 0;
}

