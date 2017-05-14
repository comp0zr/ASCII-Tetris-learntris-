#pragma once
//
//  matrix.hpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//
#ifndef matrix_h
#define matrix_h


#include <string>
#include <vector>
#include "constants.h"

using namespace std;

class Matrix {

public:

	Matrix();

	void Print();

	vector<vector<char>> matrix; //(H_SIZE, vector<char>(W_SIZE, '.'));
//	char matrix[H_SIZE][W_SIZE];
};





#endif /* matrix_h */
