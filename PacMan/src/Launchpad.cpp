#include <fstream>
#include <iostream>
#include <ctime>
#include "Launchpad.h"

namespace PacmanCGGL
{
	Launchpad::Launchpad(Board *b) : menu(new Menu()), game(new Game(b)), fps(new FPSCounter())
	{
		/* Codeless */
	}

	void Launchpad::CreateScene(void)
	{
		ClearObjects();

		RegisterObject(fps);

		if(menu->IsActive())
		{
			RegisterObject(menu);
		}
		else
		{
			RegisterObject(game);
		}
	}

	Launchpad::~Launchpad(void)
	{
		delete game;
		delete menu;
		delete fps;
	}

	void Launchpad::Draw(void)
	{
		static float angle = 0.0;
		App::Draw();

		CreateScene();

		if(menu->IsActive())
		{
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
		
			float pacman_ambient[] = {1.0f, 1.0f, 0.0f, 1.0f};
			float pacman_diffuse[] = {0.9f, 0.9f, 0.0f, 1.0f};
			float pacman_specular[] = {0.8f, 0.8f, 0.0f, 1.0f};
			float eyes_color_pac[] = {1.0f, 0.0f, 0.0f, 1.0f};
			float antipac_up_ambient[] = {0.7f, 1.0f, 0.4f, 1.0f};
			float antipac_up_diffuse[] = {0.5f, 0.8f, 0.25f, 1.0f};
			float antipac_up_specular[] = {0.3f, 0.5f, 0.1f, 1.0f};
			float antipac_down_ambient[] = {0.5f, 0.9f, 0.2f, 1.0f};
			float antipac_down_diffuse[] = {0.2f, 0.5f, 0.1f, 1.0f};
			float antipac_down_specular[] = {0.1f, 0.2f, 0.1f, 1.0f};
			float eyes_color_anti[] = {1.0f, 1.0f, 1.0f, 1.0f};
			float shininess = 100.0f;
			angle = angle + 1 < 360 ? angle + 1 : 0;
			float angle2 = angle+300;
			angle2 = angle2< 360 ? angle2: angle2-360;

			glPushMatrix();
				glMaterialf(GL_FRONT, GL_SHININESS, shininess);	

				glTranslatef(7.5, 0, 0);
				glRotatef(angle, 0, 1, 0);

				glMaterialfv(GL_FRONT, GL_AMBIENT, pacman_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, pacman_diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, pacman_specular);
				glTranslatef(-12, 0, 0);
				glutSolidSphere(PacmanCGGL::FIGURE_SIZE * 4, PacmanCGGL::SLICE * 2, PacmanCGGL::STACK * 2);

				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, eyes_color_pac);
				glColor3f(1, 1, 1);
				glTranslatef(1, 0.2, 1.5);
				glutSolidSphere(PacmanCGGL::EYE_SIZE * 4, PacmanCGGL::STACK * 2, PacmanCGGL::SLICE * 2);
				glTranslatef(-2, 0, 0);
				glutSolidSphere(PacmanCGGL::EYE_SIZE * 4, PacmanCGGL::STACK * 2, PacmanCGGL::SLICE * 2);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.5, 0, 0);
				glRotatef(angle2, 0, 1, 0);

				glMaterialfv(GL_FRONT, GL_AMBIENT, antipac_down_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, antipac_down_diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, antipac_down_specular);
				glTranslatef(-12, 0, 0);
				glRotatef(270, 1, 0, 0);
				glutSolidCone(PacmanCGGL::FIGURE_SIZE * 4, PacmanCGGL::FIGURE_SIZE * 2 * 4, PacmanCGGL::SLICE * 2, PacmanCGGL::STACK * 2);

				glMaterialfv(GL_FRONT, GL_AMBIENT, antipac_up_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, antipac_up_diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, antipac_up_specular);
				glRotatef(90, 1, 0, 0);
				glTranslatef(0, PacmanCGGL::FIGURE_SIZE * 1.6 * 4, 0);
				glutSolidSphere(PacmanCGGL::FIGURE_SIZE * 0.8 * 4, PacmanCGGL::SLICE * 2, PacmanCGGL::STACK * 2);

				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, eyes_color_anti);
				glTranslatef(0.2 * 4, 0.3 * 4, 0.3 * 4);
				glutSolidSphere(PacmanCGGL::EYE_SIZE * 4, PacmanCGGL::SLICE * 2, PacmanCGGL::STACK * 2);
				glTranslatef(-0.4 * 4, 0, 0);
				glutSolidSphere(PacmanCGGL::EYE_SIZE * 4, PacmanCGGL::SLICE * 2, PacmanCGGL::STACK * 2);
			glPopMatrix();

			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
		}
	}

	Board *CreateBoard(char *file)
	{
		return new Board(file);
	}
}

int main(int argc, char** argv)
{
	char **args = argv;
	srand((unsigned)time(0));

	PacmanCGGL::Launchpad lp(PacmanCGGL::CreateBoard(*++argv));
	lp.Run(argc, args);
}