#ifndef _PACMAN_ANTIPAC_
#define _PACMAN_ANTIPAC_

#include "Figure.h"

namespace PacmanCGGL
{
	class AntiPac : public Figure
	{
		Figure* target;
		void changeDirection(void);
		bool canMove;
	public:
		AntiPac(Vector2*, Object**, int, Figure*);
		void Draw(void);
		void Update(int);
	};
}

#endif