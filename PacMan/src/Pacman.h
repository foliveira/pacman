#ifndef _PACMAN_MR_PAC_
#define _PACMAN_MR_PAC_

#include "Figure.h"

namespace PacmanCGGL
{
	class Pacman : public Figure
	{
		int bSz;
	public:
		Pacman(Vector2*, Object**, int);
		void Draw(void);
		void Update(int);
	};
}

#endif