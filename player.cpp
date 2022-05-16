#include <SDL2/SDL.h>
#include <stdio.h>
#include "player.h"
#include "display.h"

Player::Player()
{
	
}


void Player::move(void)
{
	static const Uint8 *key;
	SDL_PumpEvents();
	key = SDL_GetKeyboardState(NULL);
	if (key[SDL_SCANCODE_RIGHT])
	{
		x+=5;
	}

	
	if (key[SDL_SCANCODE_LEFT])
	{
		x-=5;
	}
	if (key[SDL_SCANCODE_UP])
	{
		y-=5;
	}
	if (key[SDL_SCANCODE_DOWN])
	{
		y+=5;
	}
//	if (x < 0) x+=5;
//	else if (x> 2000-40) x-=5;
///	if (y < 0) y+=5;
//	else if (y > HeightWindows-40) y-=5;
//	printf("x %d y %d \n",x,y);
}

void Player::Free(void)
{
}

void Player::Affiche(SDL_Renderer *render)
{
	SDL_Color color = {255, 255, 255, 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
        	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
  	}
	SDL_Rect srcrect = {x,y,5,5};
	SDL_RenderDrawRect(render, &srcrect);
	SDL_RenderPresent(render);		
}
