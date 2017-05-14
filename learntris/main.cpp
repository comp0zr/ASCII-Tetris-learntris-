// http://en.cppreference.com/w/cpp/language/using_declaration
//
//  main.cpp
//  learntris
//
//  Created by Administrator on 5/13/17.
//
//

//#include <iostream>
#include "main.h"
#include "matrix.h"
#include "input.hpp"
#include "shape.hpp"

InputParser IN;
Tetris* game = new Tetris;


int main(int argc, const char * argv[])
{
	while(1)
	{
//		IN.Read(200);
		cin >> IN.buffer; cin.ignore();
		IN.io = (IO)commands[IN.buffer];

		switch(IN.io)
		{
			case IO::CLEAR:
				game->M.Clear();
				break;

			case IO::DISPLAY_ACTIVE:
				game->active->Display();
				break;

			case IO::GIVEN:
				game->M.Modify();
				break;

			case IO::LINES:
				game->LinesCleared();
				break;

			case IO::NEWLINE:
				cout << endl;
				break;

			case IO::PRINT:
				game->M.Print();
				break;

			case IO::QUIT:
				exit(0);
				break;

			case IO::ROTATE_CLOCKWISE:
				game->active->Rotate(1);
				break;

			case IO::ROTATE_COUNTER:
				game->active->Rotate(-1);
				break;

			case IO::SCORE:
				game->GetScore();
				break;

			case IO::SHAPE_I:
			{
				Shape* temp = new S_I;
				game->active = dynamic_cast<S_I*>(temp);
				break;
			}

			case IO::SHAPE_J:
			{
				Shape* temp = new S_J;
				game->active = dynamic_cast<S_J*>(temp);
				break;
			}

			case IO::SHAPE_L:
			{
				Shape* temp = new S_L;
				game->active = dynamic_cast<S_L*>(temp);
				break;
			}

			case IO::SHAPE_O:
			{
				Shape* temp = new S_O;
				game->active = dynamic_cast<S_O*>(temp);
				break;
			}

			case IO::SHAPE_S:
			{
				Shape* temp = new S_S;
				game->active = dynamic_cast<S_S*>(temp);
				break;
			}

			case IO::SHAPE_T:
			{
				Shape* temp = new S_T;
				game->active = dynamic_cast<S_T*>(temp);
				break;
			}

			case IO::SHAPE_Z:
			{
				Shape* temp = new S_Z;
				game->active = dynamic_cast<S_Z*>(temp);
				break;
			}

			case IO::STEP:
				game->NextStep();
				break;

			default:
				break;
		}
	}
	return 0;
}


Tetris::Tetris()
{
	time_t T;
	time(&T);
	T %= NUM_SHAPES;

	LOG(T << endl);

	score = 0;
	int randShape = T;

	randShape = 0;

	switch((TYPE)randShape)
	{
		case TYPE::I:
			active = new S_I;
			break;

		case TYPE::J:
			active = new S_J;
			break;

		case TYPE::L:
			active = new S_L;
			break;

		case TYPE::O:
			active = new S_O;
			break;

		case TYPE::S:
			active = new S_S;
			break;

		case TYPE::T:
			active = new S_T;
			break;

		case TYPE::Z:
			active = new S_Z;
			break;

		default:
			active = new Shape;
			break;
	}
}


int Tetris::GetScore()
{
	cout << score << endl;
	return score;
}


int Tetris::LinesCleared()
{
	cout << clearedLines << endl;
	return clearedLines;
}

void Tetris::NextStep()
{
	for(int i=H_SIZE-1; i>=0; i--)
	{
		if(std::count(M.matrix[i].begin(), M.matrix[i].end(), '.') == 0)
		{
			M.matrix[i] = vector<char>(10, '.');
			score += 100;
			clearedLines++;
//			if(i > 0) M.matrix[i] = M.matrix[i-1];
		}
	}
};
