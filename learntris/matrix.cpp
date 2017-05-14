//
//  matrix.cpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
	matrix.resize(H_SIZE);

	for(int i=0; i<H_SIZE; i++)
	{
		matrix[i] = vector<char>(W_SIZE, '.');
	}
}

void Matrix::Print()
{
	for(auto it : matrix)
	{
		PRINT_ARR(it, 0);
		cout << endl;
	}
}
