#include "Brick.h"
#include "Consts.h"

namespace PacmanCGGL
{
	Brick::Brick(Vector2 *p) : pos(p)
	{
		/* Codeless */
	}

	Brick::~Brick(void)
	{
		delete pos;
	}

	void Brick::Draw(void)
	{
		Object::Draw();

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		
		float mat_ambient_color[] = {0.0f, 0.2f, 0.5f, 1.0f};
		float mat_diffuse[] = {0.0f, 0.2f, 0.5f, 1.0f};
		float mat_specular[] = {0.0f, 0.2f, 0.5f, 1.0f};
		float shininess = 50.0f;

		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialf(GL_FRONT, GL_SHININESS, shininess);

			glTranslatef(pos->x + PacmanCGGL::BRICK_SIZE, PacmanCGGL::BRICK_SIZE, pos->y + PacmanCGGL::BRICK_SIZE);
			glScalef(1, 0.8, 1);
			glutSolidCube(PacmanCGGL::BRICK_SIZE * 2);
		glPopMatrix();

		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
}