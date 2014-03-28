#include "Menu.h"
#include "Keys.h"
#include "Consts.h"

namespace PacmanCGGL
{
	bool Menu::cheatActive = false;

	Menu::Menu(void) : curSelection(0), inCreds(false), active(true)
	{
		AddEntry(new MenuEntry("Novo Jogo", new Vector2(350, 180), StartGame));
		AddEntry(new MenuEntry("Creditos", new Vector2(350, 220), ShowCreds));
		AddEntry(new MenuEntry("Sair", new Vector2(350, 260), exit));
	}

	void Menu::Draw(void)
	{
		Object::Draw();

		if(!inCreds)
		{
			for(unsigned int i = 0; i < entry.size(); ++i)
				entry[i]->Draw();
		}
		else
		{
			if(Menu::cheatActive)
			{
				glColor3f(0, 1, 0);
				App::Writer->WriteImediateText(10, 15, "Cheat on: NO CLIP", GLUT_BITMAP_8_BY_13);
			}

			glColor3f(1, 1, 0);
			App::Writer->BeginWriteText();
				App::Writer->WriteText(350, 200, "Pacman CGGL", GLUT_BITMAP_TIMES_ROMAN_24);
				App::Writer->WriteText(350, 250, "Por:", MENU_FONT);
				App::Writer->WriteText(350, 300, "Fabio Oliveira - nº 30979", MENU_FONT);
				App::Writer->WriteText(350, 350, "Igor Soarez - nº 30991", MENU_FONT);
			App::Writer->EndWriteText();
		}
	}

	void Menu::Update(int deltaTime)
	{
		Object::Update(deltaTime);

		if(!inCreds)
		{
			if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_UP))
			{
				entry[curSelection]->ChangeColor(new Vector3(1, 0, 0));

				curSelection = (entry.size() + curSelection - 1) % entry.size();

				entry[curSelection]->ChangeColor(new Vector3(1, 1, 1));

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_UP);
			} 
			else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_DOWN))
			{
				entry[curSelection]->ChangeColor(new Vector3(1, 0, 0));

				curSelection = (curSelection + 1) % entry.size();

				entry[curSelection]->ChangeColor(new Vector3(1, 1, 1));

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_DOWN);
			}

			if(App::Input->IsKeyPressed(PacmanCGGL::ENTER))
			{
				App::Input->ReleaseKey(PacmanCGGL::ENTER);
				entry[curSelection]->cb(curSelection != entry.size() - 1 ? int(this) : 1);
			}
		}
		else
		{
			if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_UP))
			{
				if(!(cheatCode.size() < 2))
					cheatCode.clear();

				cheatCode.push_back(true);

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_UP);
			}
			else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_DOWN))
			{
				if(cheatCode.size() > 1 && cheatCode.size() < 4)
					cheatCode.push_back(true);
				else
					cheatCode.clear();

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_DOWN);
			}
			else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_LEFT))
			{
				if(cheatCode.size() == 4 || cheatCode.size() == 6)
					cheatCode.push_back(true);
				else
					cheatCode.clear();

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_LEFT);
			}
			else if(App::Input->IsSpecialKeyPressed(PacmanCGGL::KEY_RIGHT))
			{
				if(cheatCode.size() == 5 || cheatCode.size() == 7)
					cheatCode.push_back(true);
				else
					cheatCode.clear();

				App::Input->ReleaseSpecialKey(PacmanCGGL::KEY_RIGHT);
			}
			else if(App::Input->IsKeyPressed(PacmanCGGL::KEY_B))
			{
				if(cheatCode.size() == 8)
					cheatCode.push_back(true);
				else
					cheatCode.clear();

				App::Input->ReleaseKey(PacmanCGGL::KEY_B);
			}
			else if(App::Input->IsKeyPressed(PacmanCGGL::KEY_A))
			{
				if(cheatCode.size() == 9)
					cheatCode.push_back(true);
				else
					cheatCode.clear();
				
				Menu::cheatActive = true;

				App::Input->ReleaseKey(PacmanCGGL::KEY_A);
			}
			
			else if(App::Input->IsKeyPressed(PacmanCGGL::ESCAPE))
			{
				cheatCode.clear();
				inCreds = false;
				App::Input->ReleaseKey(PacmanCGGL::ESCAPE);
			}
		}
	}

	void Menu::AddEntry(MenuEntry *e)
	{
		if(entry.size() == 0)
			e->ChangeColor(new Vector3(1, 1, 1));

		entry.push_back(e);
	}

	/*
		Menu Entry
	*/
	MenuEntry::MenuEntry(char* t, Vector2 *p, menuCB c) : text(t), pos(p), rgb(new Vector3(1, 0, 0)), cb(c) 
	{
		/* Codeless */
	}

	MenuEntry::~MenuEntry(void)
	{
		delete rgb;
		delete pos;
	}

	void MenuEntry::Draw(void)
	{
		Object::Draw();

		glColor3f(rgb->x, rgb->y, rgb->z);
		App::Writer->WriteImediateText(pos->x, pos->y, text, MENU_FONT);
	}

	void MenuEntry::ChangeColor(cggl::Vector3 *nRGB)
	{
		delete rgb;
		rgb = nRGB;
	}

	void ShowCreds(int d)
	{
		Menu *m = (Menu*)d;
		m->ToggleCreds();
	}

	void StartGame(int d)
	{
		Menu *m = (Menu*)d;
		m->SetActive(false);
	}
}