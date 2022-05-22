#include <stdio.h>
#include "display.h"
#include "input.h"
#include "player.h"
#include "raycaster.h"
#include "map.cpp"

#define FPS 60


int main(int argc,char *argv[])
{
	int fin=1;
	int i,j,k;
	printf("hello world\n");
	Display display(20,200);
	Display rayDisplay(20+WidthWindows,200);

	Player DOOM;
	RayCaster ray;
	while(fin)
	{
		k=0;
		for(i=0;i<6;i++)
		{
			for (j=0;j<8;j++)
			{
				if (map1[k] == 1)
					display.DrawRect(j,i);
				k++;
			}
		}
		DOOM.Affiche(display.render);
		ray.RayCast(display.render,DOOM.x,DOOM.y);

		display.RenderClear();
		//display.RenderClear();
		DOOM.move();

//		display.RenderClear();
		//display.DrawBackground(20,20,20,255);
		display.Wait(10.6);
		rayDisplay.RenderClear();
		rayDisplay.DrawBackground(20,20,20,255);

		display.RenderClear();
		display.DrawBackground(20,20,20,255);

		display.Fullscreen();
		fin = Input_Check();
	}
	rayDisplay.Quit();
	display.Quit();
	return 0;
}
