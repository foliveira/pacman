#ifndef _PACMAN_LAUNCHPAD_
#define _PACMAN_LAUNCHPAD_

#include <vector>
#include <cggl/App.h>
#include "Menu.h"
#include "Game.h"
#include "Board.h"
#include "cggl/FPScounter.h"

using namespace cggl;

namespace PacmanCGGL
{
	class Launchpad : public App
	{
		Menu *menu;
		Game *game;
		FPSCounter *fps;
	public:
		Launchpad(Board*);
		~Launchpad(void);
		void CreateScene(void);
		void Draw(void);
	};
}

#endif