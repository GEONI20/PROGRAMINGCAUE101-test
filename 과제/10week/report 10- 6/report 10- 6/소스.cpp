#include <stdio.h>

typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK} COLOR;
typedef enum { UP, DOWN, LEFT, RIGHT} ARROW;

int main()
{
	COLOR my_color = YELLOW, c;
	ARROW direction = UP;

	for (c = CYAN; c <= BLACK;)
	{
		direction++;
		direction = direction % 4;
		if (c == my_color)
		{
			break;
		}

		switch (direction)
		{
		case UP:  printf("direction : up");
		case DOWN: printf("direction : down");
		case LEFT: printf("direction : left");
		case RIGHT: printf("direction : right");
		}
		return 0;
	}
}