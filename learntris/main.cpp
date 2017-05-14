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

InputParser IN;
Tetris* game = new Tetris;


int main(int argc, const char * argv[])
{
//	Matrix M;
//	char buffer[200];

	while(1)
	{
		int c = IN.Read(200);

		switch(IN.io)
		{
			case IO::CLEAR:
				game->M.Clear();
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
