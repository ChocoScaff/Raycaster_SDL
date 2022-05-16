#include <SDL2/SDL.h>

class RayCaster
{
	public:
		RayCaster();

		void RayCast(SDL_Renderer *render,int x,int y);
};
