#ifndef _PACMAN_GAME_
#define _PACMAN_GAME_

#include <vector>
#include <cggl/App.h>
#include "Board.h"

using namespace cggl;

namespace PacmanCGGL
{
	class Game : public Object
	{
		Board *board;
	public:
		Game(Board*);
		~Game(void);
		void Draw(void);
		void Update(int);
	};
}

#endif