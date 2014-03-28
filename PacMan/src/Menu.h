#ifndef _PACMAN_MENU_
#define _PACMAN_MENU_

#include <cggl/App.h>
#include <vector>

#define MENU_FONT GLUT_BITMAP_HELVETICA_18

using namespace cggl;

namespace PacmanCGGL
{
	typedef void(*menuCB)(int);

	void ShowCreds(int);
	void StartGame(int);

	class MenuEntry;

	class Menu : public Object
	{
		int curSelection;
		std::vector<MenuEntry*> entry;
		bool inCreds;
		bool active;
		std::vector<bool> cheatCode;
		static bool cheatActive;
	public:
		Menu(void);
		void Draw(void);
		void Update(int);
		void AddEntry(MenuEntry*);
		
		static bool IsCheatActive(void) { return cheatActive; }
		
		inline void ToggleCreds(void) { inCreds = !inCreds; }
		inline void SetActive(bool t) { active = t; }
		inline bool IsActive(void) const { return active; }
	};

	class MenuEntry : public Object
	{
		char* text;
		Vector3* rgb;
		Vector2* pos;
	public:
		menuCB cb;
		MenuEntry(char*, Vector2*, menuCB);
		~MenuEntry(void);
		void Draw(void);
		void ChangeColor(Vector3*);
	};
}

#endif