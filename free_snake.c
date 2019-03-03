#include "snake.h"


void FreeSnake (struct snake *s)
{
	struct list *l = s->s;
	struct list *save = NULL;

	while (l)
	{
		save = l->next;
		free (l);
		l = save;
	}
}

void FreeTail (struct snake *s)
{
	struct list *ptr = s->s, *last = NULL;
	if (!ptr)
	{
		return ;
	}

	while (ptr->next)
	{
		last = ptr;
		ptr = ptr->next;
	}

	free (ptr);
	last->next = NULL;
}

