#ifndef _PACMAN_HOORAY_GUM_
#define _PACMAN_HOORAY_GUM_

#include <cggl/App.h>

using namespace cggl;

namespace PacmanCGGL
{
	class Gum : public Object
	{
		Vector2 *pos;
	public:
		Gum(Vector2*);
		~Gum(void);
		void Draw(void);
	};
}

#endif