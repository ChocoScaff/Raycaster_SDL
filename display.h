#include <SDL2/SDL.h>

#define WidthWindows 640
#define HeightWindows 480

class Display
{
	private:
		
		SDL_Window *window = NULL;
	public:

		SDL_Renderer *render = NULL;
		Display();
		void Quit(void);
		void RenderClear(void);
		void DrawBackground(unsigned char R,unsigned char G,unsigned char B,unsigned char O);
		char Fullscreen(void);
		void Wait(unsigned int time);
		void DrawRect(int x,int y);
};
