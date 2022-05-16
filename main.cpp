#include <stdio.h>
#include "display.h"
#include "input.h"
#include "player.h"
#include "raycaster.h"

#define FPS 60


int main(int argc,char *argv[])
{
	int fin=1;
	printf("hello world\n");
	Display display;
	Player DOOM;
	RayCaster ray;
	while(fin)
	{
		DOOM.Affiche(display.render);
		ray.RayCast(display.render,DOOM.x,DOOM.y);

		//display.RenderClear();
		DOOM.move();

		//display.DrawBackground(20,20,20,255);
		display.Wait(10.6);

		display.RenderClear();
		display.DrawBackground(20,20,20,255);

		display.Fullscreen();
		fin = Input_Check();
	}
	display.Quit();
	return 0;
}
