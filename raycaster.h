#include <SDL2/SDL.h>

class RayCaster
{
	private:
		double Pa=0;
	public:
		RayCaster();

		void RayCast(SDL_Renderer *render,int x,int y);
};


void checkCollision(int x1,int y1,int x2,int y2);
