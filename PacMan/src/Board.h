#ifndef _PACMAN_BOARD_
#define _PACMAN_BOARD_

#include <vector>
#include <cggl/App.h>
#include "Figure.h"
#include "Pacman.h"
#include "Antipac.h"

using namespace cggl;

#define NUMBER_OF_ANTIPACS 2

namespace PacmanCGGL
{
	class Board : public Object
	{
		int size;
		Pacman *pacman;		
		std::vector<AntiPac*> antipac;
		Object* (*objects);
	public:
		static int numOfGums;
		Board(char*);
		~Board(void);
		void Draw(void);
		void Update(int);
		inline int GetSize(void) const { return size; }
	};
}
#endif