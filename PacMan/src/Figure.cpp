#include <cmath>
#include "Figure.h"
#include "Brick.h"

namespace PacmanCGGL
{
	bool Figure::freeze = false;

	Figure::Figure(Vector2* p, Object** b, int sz) : pos(p), board(b), brdSz(sz)
	{
		rot = 90.0 * PacmanCGGL::RIGHT;
	}

	Figure::~Figure(void)
	{
		delete pos;
	}
	
	Vector2 Figure::getMovedPos(void)
	{
		Vector2 newPos = *pos;

		if(direction == PacmanCGGL::RIGHT)
		{
			newPos.x += PacmanCGGL::FIGURE_SPEED;
			newPos.y = floor(newPos.y + 0.5);
		}
		else if(direction == PacmanCGGL::LEFT)
		{
			newPos.x -= PacmanCGGL::FIGURE_SPEED;
			newPos.y = floor(newPos.y + 0.5);
		}
		else if(direction == PacmanCGGL::UP)
		{
			newPos.x = floor(newPos.x + 0.5);
			newPos.y -= PacmanCGGL::FIGURE_SPEED;
		}
		else if(direction == PacmanCGGL::DOWN)
		{
			newPos.x = floor(newPos.x + 0.5);
			newPos.y += PacmanCGGL::FIGURE_SPEED;
		}

		return newPos;
	}

	bool Figure::Move(void)
	{
		Vector2 newPos = getMovedPos();
		bool res;

		if(res = CanMoveTo(newPos)) 
			*pos = newPos;

		return res;
	}

	void Figure::MoveForSure(void)
	{
		*pos = getMovedPos();
	}

	bool Figure::CanMoveTo(Vector2& nPos)
	{
		int a = 0;

		if(direction == PacmanCGGL::RIGHT)
			a = (int)(floor(nPos.x + 1) + brdSz * floor(nPos.y + 0.5));
		else if(direction == PacmanCGGL::LEFT)
			a = (int)(floor(nPos.x) + brdSz * floor(nPos.y + 0.5));
		else if(direction == PacmanCGGL::UP)
			a = (int)(floor(nPos.x + 0.5) + brdSz * floor(nPos.y));
		else if(direction == PacmanCGGL::DOWN)
			a = (int)(floor(nPos.x + 0.5) + brdSz * floor(nPos.y + 1));

		return !(board[a]) || (typeid(*board[a]) != typeid(Brick));
	} 
}
