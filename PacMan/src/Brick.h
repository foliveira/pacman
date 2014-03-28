#ifndef _PACMAN_BRICK_
#define _PACMAN_BRICK_

#include <cggl/App.h>

using namespace cggl;

namespace PacmanCGGL
{
	class Brick : public Object
	{
		Vector2 *pos;
	public:
		Brick(Vector2*);
		~Brick(void);
		void Draw(void);
	};
}

#endif