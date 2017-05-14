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
#include "shape.hpp"

using namespace std;

class Matrix {

public:

	Matrix();

	void Print();
	void Modify();
	void Clear();

	void PrintWithActive(pair<int, int> sz, pair<int, int> pos, Shape *active);

	vector<vector<char>> matrix;
};





#endif /* matrix_h */
