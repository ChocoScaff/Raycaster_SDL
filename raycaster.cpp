#include <math.h>
#include "display.h"
#include "raycaster.h"
#include <SDL2/SDL.h>
#include <stdio.h>

#define PI 3.14159
#define WidthTexture 40
#define HeightTexture 80
#define ScreenDistance 300

RayCaster::RayCaster()
{
	/*
 	screenWidth
	+-----+------+  -
	\     |     /   ^
	 \    |    /    |
	  \   |   /     | screenDistance aka projectionPlaneDistance
	   \  |  /      |
 	    \fov/       |
	     \|/        v
	      v         -
	tan(angle) = opposite / adjacent
	tan(fov/2) = (screenwidth/2) / screenDistance
	screenDistance = (screenwidth/2) / tan(fov/2)

      screenX
            <------
            +-----+------+  +-
            \     |     /   |
             \    |    /    |
rayViewDist   \   |   /     | screenDistance aka projectionPlaneDistance
               \  |  /      |
                \a| /       |
                 \|/        |
                  v         |_
	// Pythagoras
	rayViewDist = squareroot(screenX*screenX + screenDistance*screenDistance)
	// asin is the reverse of sin
	asin(opposite / hypotenuse) = angle
	angle = asin(opposite / hypotenuse)
	a = asin( screenX / rayViewDist )
	OR
	a = atan( screenX / screenDistance )
	*/
	

}

void RayCaster::RayCast(SDL_Renderer *render,int x,int y)
{
	static const Uint8 *key;
	key = SDL_GetKeyboardState(NULL);
		
	if (key[SDL_SCANCODE_Q])
	{
		Pa+=0.1; if (Pa > 2*PI) Pa=0;
		//printf("%f\n",Pa);
	}
	if (key[SDL_SCANCODE_E])
	{
		Pa-=0.1; if (Pa < 0) Pa=2*PI;
		//printf("%f\n",Pa);
	}
	
	SDL_Color color = {255, 255, 255, 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
      	 	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
	}
   	SDL_Point point[2];
	point[0].x = x;
	point[0].y = y;
	point[1].x = sin(Pa)*ScreenDistance+x; 
	point[1].y = cos(Pa)*ScreenDistance+y;
	SDL_RenderDrawLines(render, point, 2);
	
	color = {0, 255, 0, 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
      	 	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
	}
	for (double i=0.1;i<0.5;i=i+0.1)
	{

		point[0].x = x;
		point[0].y = y;
		point[1].x = sin(Pa-i)*ScreenDistance+x;
		point[1].y = cos(Pa-i)*ScreenDistance+y;
		SDL_RenderDrawLines(render, point, 2);

	}

	color = {255, 0, 0, 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
      	 	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
	}

	for (double i=0.1;i<0.5;i=i+0.1)
	{

		point[0].x = x;
		point[0].y = y;
		point[1].x = sin(Pa+i)*ScreenDistance+x;
		point[1].y = cos(Pa+i)*ScreenDistance+y;
		SDL_RenderDrawLines(render, point, 2);

	}
}
