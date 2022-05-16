#include "display.h"


Display::Display()
{
    if(0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Error SDL_Init : %s",SDL_GetError());
    }

    window = SDL_CreateWindow("RPG",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WidthWindows,HeightWindows,SDL_WINDOW_BORDERLESS);
    if(NULL == window)
    {
        fprintf(stderr, "Error SDL_CreateWindow : %s",SDL_GetError());
    }

    render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(NULL == render)
    {
        fprintf(stderr, "Error SDL_CreateRenderer : %s",SDL_GetError());
        render = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
        if(NULL == render)
        {
            fprintf(stderr, "Error SDL_CreateRenderer : %s",SDL_GetError());
        }
    }
}

void Display::Quit(void)
{
    if(NULL != render) SDL_DestroyRenderer(render);
    if(NULL != window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::RenderClear(void)
{
    SDL_RenderPresent(render);
}
void Display::DrawBackground(unsigned char R,unsigned char G,unsigned char B,unsigned char O)
{
    SDL_Color color = {R, G, B, O};

    if(0 != SDL_SetRenderDrawColor(render, color.r,color.g, color.b, color.a))
    {
        fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
    }

    if(0 != SDL_RenderClear(render))
    {
        fprintf(stderr,"Error SDL_SetRenderDrawColor : %s",SDL_GetError());
    }

    //SDL_RenderPresent(render);
    
}

char Display::Fullscreen(void)
{
    static char fullscreen='b';
    const Uint8 *key;    
    key = SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_F1])
    {
    	if (fullscreen == 'b')
    	{
        	SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
	        fullscreen = 'f';
    	}
    	else if (fullscreen == 'f')
    	{
        	SDL_SetWindowFullscreen(window,SDL_WINDOW_BORDERLESS);
	        fullscreen = 'b';
    	}
	SDL_Delay(1000);
    }
    if(window == NULL)
    {
        fprintf(stderr, "Error SDL_CreateWindow : %s",SDL_GetError());
        return -1;
    }
    return 0;
}

void Display::Wait(unsigned int time)
{
	SDL_Delay(time);
}

void Display::DrawRect(int x,int y)
{
	SDL_SetRenderDrawColor(render,255,0,0,255);	
	SDL_Rect rect = {WidthWindows/2,HeightWindows-40,40,40};
	SDL_RenderFillRect(render, &rect);
	SDL_RenderPresent(render);
}
