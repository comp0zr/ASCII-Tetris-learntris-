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
	Matrix M;

//	S_I S;
//	S.Display();

	while(1)
	{
		int c = IN.Read(200);

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

			case IO::PRINT:
				game->M.Print();
				break;

			case IO::QUIT:
				exit(0);
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

			case IO::SHAPE_O:
			{
				Shape* temp = new S_O;
				game->active = dynamic_cast<S_O*>(temp);
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
	score = 0;
	int randShape = 0; //rand() % NUM_SHAPES;

	if(randShape == TYPE::I)
	{
		active = new Shape();
	}
	else if(randShape == 1) {}
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
