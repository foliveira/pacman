#include "Board.h"
#include "Brick.h"
#include "Gum.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace PacmanCGGL
{
	int Board::numOfGums = 0;

	Board::Board(char* filename)
	{
		std::ifstream mapfile;
		char c = '\0';
			
		if(!filename) 
			filename = "default.map";

		mapfile.open(filename);

		if(!mapfile)
		{
			std::cerr << "Error: Can't open map filename " << filename << std::endl;
            exit(1);
		}

		mapfile >> size;

		int arraySz = size * size;
		int antiPos = 0;
		int antiCnt = NUMBER_OF_ANTIPACS;
		objects = new Object*[arraySz];

		for(int i = 0; i < arraySz; ++i)
		{
			mapfile >> c;

			if(c == '#')
				objects[i] = new Brick(new Vector2(i % size, i / size));
			else if(c == '-')
			{
				objects[i] = new Gum(new Vector2(i % size, i / size));
				++Board::numOfGums;
			}
			else 
			{
				if(c == 'S')
					pacman = new Pacman(new Vector2(i % size, i / size), objects, size);
				else if(c == 'A')
					antiPos = i;
				else 
				{
					std::cerr << "Error: Corrupt map filename " << filename << std::endl;
					exit(1);
				}

				objects[i] = PacmanCGGL::VOID;;
			}
		}

		while(antiCnt--)
			antipac.push_back(new AntiPac((new Vector2(antiPos % size, antiPos / size)), objects, size, pacman));

		mapfile.close();
	}

	Board::~Board(void)
	{
		delete pacman;

		for(unsigned int i = 0; i < antipac.size(); ++i)
			delete antipac[i];

		for(int i = 0; i < size; ++i)
		{
			if(objects[i])
				delete objects[i];
		}
	}

	void Board::Draw(void)
	{
		Object::Draw();

		if(Figure::freeze)
		{
			glColor3f(1, 0, 0);
			App::Writer->WriteImediateText(350, 30, Board::numOfGums == 0 ? "GANHOU O JOGO!" : "PERDEU O JOGO!", ((void*)8));
		}

		glColor3f(1, 1, 1);
		std::stringstream ss;
		ss << Board::numOfGums;
		App::Writer->BeginWriteText();
		App::Writer->WriteText(10, 35, "Gums: ", GLUT_BITMAP_HELVETICA_18);
		App::Writer->WriteText(75, 35, ss.str().c_str(), GLUT_BITMAP_HELVETICA_18);
		App::Writer->EndWriteText();

		for(int i = 0; i < size * size; ++i)
		{
			if(objects[i])
				objects[i]->Draw();
		}

		for(unsigned int i = 0; i < antipac.size(); ++i)
			antipac[i]->Draw();

		pacman->Draw();
	}

	void Board::Update(int deltaTime)
	{
		Object::Update(deltaTime);

		pacman->Update(deltaTime);

		for(unsigned int i = 0; i < antipac.size(); ++i)
			antipac[i]->Update(deltaTime);
	}
}