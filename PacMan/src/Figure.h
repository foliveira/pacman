#ifndef _PACMAN_FIGURE_
#define _PACMAN_FIGURE_

#include <vector>
#include <cggl/App.h>
#include "Consts.h"

using namespace cggl;

namespace PacmanCGGL
{
	class Figure : public Object
	{
		float rot;
	protected:
		Object** board;
		int brdSz;
		Vector2 getMovedPos(void);
		unsigned char direction;
	public:
		static bool freeze;
		Vector2 *pos;
		Figure(Vector2*, Object**, int);
		virtual ~Figure(void);
		void Draw(void) =0;
		void Update(int) =0;
		void MoveForSure(void);
		bool Move(void);
		bool CanMoveTo(Vector2&);

		inline float Rotation(void) { return direction == PacmanCGGL::STOP ? rot : rot = direction * 90.0; };
	};
}
#endif