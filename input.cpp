#include "input.h"
#include "display.h"
#include <stdio.h>

SDL_Event event;

int Input_Check(void)
{
	const Uint8 *key;

	key = SDL_GetKeyboardState(NULL);
	if (key[SDL_SCANCODE_ESCAPE]==1)
	{
		return 0;
	}
	return 1;
}
