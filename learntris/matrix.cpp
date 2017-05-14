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


void Matrix::PrintWithActive(pair<int, int> sz, pair<int, int> pos, Shape &active)
{
	LOG(pos.first << ", " << pos.second << endl);

	for(int i=0; i<22; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i >= pos.first  && i < pos.first + sz.first)
			{
				if(j >= pos.second && j < pos.second + sz.second)
				{
					cout << (char)toupper(active.CharAt(i, j - pos.second)) << ' ';
					continue;
				}
			}
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
//	for(int i=0; i<sz.first; i++)
//	{
//		for(int j=pos.second; j<pos.second + sz.second; j++)
//		{
//			matrix[i][j] = active.CharAt(i, j - pos.second);
//		}
//	}
}


void Matrix::Modify()
{
	cin.clear();

	for(int i=0; i<22; i++)
	{
		string s;
		try {
			getline(cin, s, '\n');

			if(s.find_first_not_of(".bcgmory ") != string::npos)
			{	throw ('L');	}

		} catch(char L) {
			cerr << "Invalid input. Please try again: ";
			continue;
		}

		int index = 0;
		for(auto c : s)
		{
			if(isalpha(c) || c == '.')
			{
				matrix[i][index] = c;
				index++;
			}
		}
//		PRINT_ARR(matrix[i], 1);
//		cerr << endl;
	}
}

void Matrix::Clear()
{
	matrix.clear();
	matrix = vector<vector<char>>(22, vector<char>(10, '.'));
}
