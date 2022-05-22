#include <SDL2/SDL.h>

class Player
{
	private:
	public:
		Player();
		int y=200;
		int x=200;
		void move(void);
		void drawPlayer(void);
		void Free(void);
		void Affiche(SDL_Renderer *render);
};
