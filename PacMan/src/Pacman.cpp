#include <cmath>
#include <iostream>
#include "Board.h"
#include "Pacman.h"
#include "Keys.h"
#include "Menu.h"
#include "Gum.h"

namespace PacmanCGGL
{
	extern int cheatActive;

	Pacman::Pacman(Vector2* p, Object** b, int sz) : Figure(p, b, sz)
	{
		direction = PacmanCGGL::RIGHT;
		bSz = sz * sz;
	}

	void Pacman::Draw(void)
	{
		Object::Draw();

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		
		float pacman_ambient[] = {1.0f, 1.0f, 0.0f, 1.0f};
		float pacman_diffuse[] = {0.9f, 0.9f, 0.0f, 1.0f};
		float pacman_specular[] = {0.8f, 0.8f, 0.0f, 1.0f};
		float eyes_color[] = {1.0f, 0.0f, 0.0f, 1.0f};
		float shininess = 100.0f;

		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, pacman_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, pacman_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, pacman_specular);
			glMaterialf(GL_FRONT, GL_SHININESS, shininess);			
			glTranslatef(pos->x + PacmanCGGL::FIGURE_SIZE, PacmanCGGL::FIGURE_SIZE, pos->y + PacmanCGGL::FIGURE_SIZE);
			glutSolidSphere(PacmanCGGL::FIGURE_SIZE, PacmanCGGL::SLICE, PacmanCGGL::STACK);

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

	void Pacman::Update(int deltaTime)
	{
		Object::Update(deltaTime);

		if(Figure::freeze)
			return;

		if(Menu::IsCheatActive())
			MoveForSure();
		else
			Move();

		int ind = floor(0.5 + pos->x) + brdSz * floor(0.5 + pos->y);
		if(ind >= 0 && ind < bSz && board[ind] != 0 && typeid(*board[ind]) == typeid(Gum) )	
		{
			delete board[ind]; 
			board[ind] = PacmanCGGL::VOID; 
			if(--Board::numOfGums == 0)
				Figure::freeze = true;
		}

		if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_UP))
		{
			direction = PacmanCGGL::UP;
			App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_UP);
		}
		else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_DOWN))
		{
			direction = PacmanCGGL::DOWN;
			App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_DOWN);
		}
		else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_LEFT))
		{
			direction = PacmanCGGL::LEFT;
			App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_LEFT);
		}
		else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_RIGHT))
		{
			direction = PacmanCGGL::RIGHT;
			App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_RIGHT);
		}
	}
}