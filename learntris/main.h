//
//  main.h
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//
#pragma once

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
#include "shape.hpp"

#endif /* main_h */


class Tetris
{
public:
	Matrix M;
	Shape* active;

public:
	Tetris();
	int GetScore();
	int LinesCleared();

	void SpawnActive();
	void Falling();
	void StopActive();
	void NextStep();

private:
	int score = 0;
	int clearedLines = 0;
	int x, y;
};
