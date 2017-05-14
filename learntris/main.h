//
//  main.h
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//
#pragma once

//#include "constants.h"




#ifndef main_h
#define main_h


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "input.hpp"
#include "matrix.h"

#endif /* main_h */

class Tetris
{
public:
	Matrix M;

public:
	Tetris();
	int GetScore();
	int LinesCleared();

	void NextStep();

private:
	int score = 0;
	int clearedLines = 0;
};
