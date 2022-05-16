#include <SDL2/SDL.h>

class RayCaster
{
	private:
		double Pa=0;
	public:
		RayCaster();

		void RayCast(SDL_Renderer *render,int x,int y);
};
