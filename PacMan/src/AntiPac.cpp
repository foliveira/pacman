#include <cmath>
#include "AntiPac.h"

namespace PacmanCGGL
{
	AntiPac::AntiPac(Vector2* p, Object** b, int sz, Figure* t) : Figure(p, b, sz), target(t)
	{
		canMove = true;
	}

	void AntiPac::Draw(void)
	{
		Object::Draw();

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		float antipac_up_ambient[] = {0.7f, 1.0f, 0.4f, 1.0f};
		float antipac_up_diffuse[] = {0.5f, 0.8f, 0.25f, 1.0f};
		float antipac_up_specular[] = {0.3f, 0.5f, 0.1f, 1.0f};
		float antipac_down_ambient[] = {0.5f, 0.9f, 0.2f, 1.0f};
		float antipac_down_diffuse[] = {0.2f, 0.5f, 0.1f, 1.0f};
		float antipac_down_specular[] = {0.1f, 0.2f, 0.1f, 1.0f};
		float eyes_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
		float shininess = 100.0f;

		glPushMatrix();
			glMaterialf(GL_FRONT, GL_SHININESS, shininess);

			glMaterialfv(GL_FRONT, GL_AMBIENT, antipac_down_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, antipac_down_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, antipac_down_specular);
			glTranslatef(pos->x + PacmanCGGL::FIGURE_SIZE, 0, pos->y + PacmanCGGL::FIGURE_SIZE);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(PacmanCGGL::FIGURE_SIZE, PacmanCGGL::FIGURE_SIZE * 2, PacmanCGGL::SLICE, PacmanCGGL::STACK);

			glMaterialfv(GL_FRONT, GL_AMBIENT, antipac_up_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, antipac_up_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, antipac_up_specular);
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, PacmanCGGL::FIGURE_SIZE * 1.6, 0);
			glutSolidSphere(PacmanCGGL::FIGURE_SIZE * 0.8, PacmanCGGL::SLICE, PacmanCGGL::STACK);

			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, eyes_color);
			glRotatef(Rotation(), 0, 1, 0);
			glTranslatef(0.2, 0.3, 0.3);
			glutSolidSphere(PacmanCGGL::EYE_SIZE, PacmanCGGL::SLICE, PacmanCGGL::STACK);
			glTranslatef(-0.4, 0, 0);
			glutSolidSphere(PacmanCGGL::EYE_SIZE, PacmanCGGL::SLICE, PacmanCGGL::STACK);
		glPopMatrix();

		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}

	void AntiPac::Update(int deltaTime)
	{
		static int dT=0;

		Object::Update(deltaTime);

		if(Figure::freeze)
			return;
		
		dT += deltaTime;
		
		if(!(canMove = Move()) || dT > 350) 
		{ 
			changeDirection();
			dT = 0;
		}

		if(floor(0.5 + pos->x) == floor(0.5 + target->pos->x) && floor(0.5 + pos->y) == floor(0.5 + target->pos->y)) 
		{
			Figure::freeze = true;
			direction = PacmanCGGL::STOP;
		}
	}

	void AntiPac::changeDirection(void)
	{
		double prob = (((double)rand()) / RAND_MAX);

		if(prob > 0.85) 
			direction = direction == 3 ? 0 : direction + 1;
		else if(prob < 0.15) 
			direction = direction == 0 ? 3 : direction - 1;
		else
		{
			int distX = (target->pos->x) - (pos->x); 
			int distY = (target->pos->y) - (pos->y);
			int preferedDir1 = 0; 
			int preferedDir2 = 0;

			if(abs(distX) > abs(distY))
			{
				preferedDir1 = distX > 0 ? PacmanCGGL::RIGHT : PacmanCGGL::LEFT;
				preferedDir2 = distY > 0 ? PacmanCGGL::DOWN : PacmanCGGL::UP;
			}
			else
			{
				preferedDir1 = distY > 0 ? PacmanCGGL::DOWN : PacmanCGGL::UP;
				preferedDir2 = distX > 0 ? PacmanCGGL::RIGHT : PacmanCGGL::LEFT;
			}

			if(!canMove && preferedDir1 == direction) 
				direction = preferedDir2;
			else 
				direction = preferedDir1;
		}		
	}
}
