#include <math.h>
#include "display.h"
#include "raycaster.h"
#include <SDL2/SDL.h>

#define PI 3.14159
#define FOV PI/2
#define ScreenDistance (WitdthWindows/2)/tan(FOV/2)
#define WidthTexture 40
#define HeightTexture 80

RayCaster::RayCaster()
{

}

void RayCaster::RayCast(SDL_Renderer *render,int x,int y)
{
	SDL_Color color = {255, 255, 255, 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
        	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
	}
   	SDL_Point point[2];
	for (int i=0;i<5;i++)
	{
		point[0].x = x;
		point[0].y = y;
		point[1].x = x+i*40;
		point[1].y = HeightWindows;
		SDL_RenderDrawLines(render, point, 2);
	}
	SDL_RenderPresent(render);
}
