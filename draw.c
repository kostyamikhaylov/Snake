#include "snake.h"

void Draw (struct snake *s)
{
	int i = 0, j = 0;
	system ("clear");
	
	for (i = 0; i < LINES; i++)
		for (j = 0; j < WIDTH; j++)
			arr[i][j] = '-';
	
	struct list *ptr = s->s;

	while (ptr)
	{
		arr[ptr->position.line][ptr->position.column] = '0';
		ptr = ptr->next;
	}
	
	for (i = 0; i < LINES; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			printf ("%c", arr[i][j]);
		}
		puts ("");
	}
}

