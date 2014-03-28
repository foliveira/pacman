#ifndef _PACMAN_VALUES_
#define _PACMAN_VALUES_

namespace PacmanCGGL
{
	/* Gameplay */
	static const float BRICK_SIZE = 0.5;
	static const float GUM_SIZE = 0.1;
	static const float FIGURE_SIZE = 0.5;
	static const float EYE_SIZE = 0.1;
	static const float FIGURE_SPEED = 0.03;

	/* Quality */
	static const float SLICE = 16;
	static const float STACK = 8;

	/* Board */
	static const int VOID = 0;

	/* Directions */
	static const int DOWN = 0;
	static const int RIGHT = 1;
	static const int UP = 2;
	static const int LEFT = 3;
	static const int STOP = 4;
}

#endif