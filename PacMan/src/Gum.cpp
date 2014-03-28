#include "Gum.h"
#include "Consts.h"

namespace PacmanCGGL
{
	Gum::Gum(Vector2 *p) : pos(p)
	{
		/* Codeless */
	}

	Gum::~Gum(void)
	{
		delete pos;
	}

	void Gum::Draw(void)
	{
		glPushMatrix();
			glColor3f(1, 1, 1);
			glTranslatef(pos->x + PacmanCGGL::BRICK_SIZE, PacmanCGGL::BRICK_SIZE + PacmanCGGL::GUM_SIZE, pos->y + PacmanCGGL::BRICK_SIZE);
			glutSolidSphere(PacmanCGGL::GUM_SIZE, PacmanCGGL::SLICE / 4, PacmanCGGL::STACK / 4);
		glPopMatrix();
	}
}