#include "Game.h"
#include "Keys.h"
#include "Menu.h"

namespace PacmanCGGL
{
	extern int cheatActive;

	Game::Game(Board* b) : board(b)
	{
		App::Camera->LookAt(Vector3(board->GetSize() / 2, board->GetSize(), board->GetSize() * 1.5 ),
			Vector3(board->GetSize() / 2, 0, board->GetSize() / 2), 
			Vector3(0, 1, 0));
	}

	Game::~Game(void)
	{
		delete board;
	}

	void Game::Draw(void)
	{
		Object::Draw();

		if(Menu::IsCheatActive())
		{
			glColor3f(0, 1, 0);
			App::Writer->WriteImediateText(10, 15, "Cheating", GLUT_BITMAP_8_BY_13);
		}

		board->Draw();
	}

	void Game::Update(int deltaTime)
	{
		Object::Update(deltaTime);

		if(App::Input->IsKeyPressed(PacmanCGGL::KEY_ONE))
		{
			App::Camera->LookAt(Vector3(board->GetSize() / 2, board->GetSize(), board->GetSize() * 1.5 ),
			Vector3(board->GetSize() / 2, 0, board->GetSize() / 2), Vector3(0, 1, 0));
			App::Input->ReleaseKey(PacmanCGGL::KEY_ONE);
		}
		else if(App::Input->IsKeyPressed(PacmanCGGL::KEY_TWO))
		{
			App::Camera->LookAt(Vector3(board->GetSize() / 2, board->GetSize() / 2, board->GetSize() * 1.5 ),
			Vector3(board->GetSize() / 2, 0, board->GetSize() / 2), Vector3(0, 1, 0));
			App::Input->ReleaseKey(PacmanCGGL::KEY_ONE);
		}
		else if(App::Input->IsKeyPressed(PacmanCGGL::KEY_THREE))
		{
			App::Camera->LookAt(Vector3(board->GetSize() / 2, board->GetSize() * 1.5, board->GetSize() / 1.8),
			Vector3(board->GetSize() / 2, 0, board->GetSize() / 2), Vector3(0, 1, 0));
			App::Input->ReleaseKey(PacmanCGGL::KEY_ONE);
		}

		board->Update(deltaTime);

		if(App::Input->IsKeyPressed(PacmanCGGL::ESCAPE))
			exit(1);
	}
}