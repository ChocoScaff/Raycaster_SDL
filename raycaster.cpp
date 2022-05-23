#include <math.h>
#include "display.h"
#include "raycaster.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "map.cpp"

#define PI 3.14159
#define WidthTexture 40
#define HeightTexture 80
#define ScreenDistance 300

RayCaster::RayCaster()
{

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
	
	SDL_Color color = {255, 0,0 , 255};

	if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
   	{
      	 	fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
	}
	int xr=sin(Pa)*ScreenDistance+x; 
	int yr=cos(Pa)*ScreenDistance+y;
   	SDL_Point point[2];
	point[0].x = x;
	point[0].y = y;
	point[1].x = xr;
	point[1].y = yr;
	SDL_RenderDrawLines(render, point, 2);
	
	printf("x : %d y : %d xr : %d yr :  %d dx : %d dy : %d \n",x,y,xr,yr,x-xr,y-yr);
	//regarder collision

	int k=0;
	for(int i=0;i<6;i++)
	{
		for (int j=0;j<8;j++)
		{
			if (map1[k] != 0)
				checkCollision(xr,yr,j*80,i*80);	

			k++;
		}
	}
	printf("check complete\n");
	/*
	for (double i=0.1;i<0.5;i=i+0.1)
	{

		point[0].x = x;
		point[0].y = y;
		point[1].x = sin(Pa-i)*ScreenDistance+x;
		point[1].y = cos(Pa-i)*ScreenDistance+y;
		SDL_RenderDrawLines(render, point, 2);

	}


	for (double i=0.1;i<0.5;i=i+0.1)
	{

		point[0].x = x;
		point[0].y = y;
		point[1].x = sin(Pa+i)*ScreenDistance+x;
		point[1].y = cos(Pa+i)*ScreenDistance+y;
		SDL_RenderDrawLines(render, point, 2);

	}
	*/
}

void checkCollision(int x1,int y1,int x2,int y2)
{
	SDL_bool coli;
	SDL_Rect rect1 = {x1,y1,1,1};

	SDL_Rect rect2 = {x2,y2,80,80};
	coli = SDL_HasIntersection(&rect1,&rect2);

	if (coli == SDL_TRUE)
	{
		printf("collision\n");
	}
}

