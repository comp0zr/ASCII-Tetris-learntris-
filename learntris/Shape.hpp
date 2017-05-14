//
//  Shape.hpp
//  Tetris
//
//  Created by Administrator on 5/14/17.
//
//
#pragma once

#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>
#include <string>
#include <vector>
#include "constants.h"
using namespace std;

typedef vector<vector<char>> shape;

enum class TYPE	{	I = 0,     J,	L,	O,	S,	T,    Z	};



class Shape
{
public:

	Shape()
	{
		graphic = shape(h, vector<char>(w, '.'));
		graphic =	{{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	}};
	}
	Shape(int h_sz, int w_sz, char col) : h(h_sz), w(w_sz), color(col)
	{
		x = (10 - w) / 2;
		y = 0;
	}

	void Display()
	{
		for(auto r : graphic)
		{PRINT_ARR(r, 0); std::cout << endl;}
	}

	pair<int, int> GetSize()
	{
		return { h, w };
	}

	pair<int, int> GetPos()
	{
		return { y,  x };
	}

	void SetPos(int next_y, int next_x)
	{
		y = next_y;
		x = next_x;
	}

	char CharAt(int y, int x)
	{
//		return 'x';
		return graphic[y][x];
	}

	virtual void Rotate(int r) {};


protected:
	char color;
	int w, h;
	int x, y;
	shape graphic;

	int rotation = 0;
};


class S_I : public Shape
{
public:
	S_I() : Shape(4, 4, 'c')
	{
		graphic = shape(4, vector<char>(4, '.'));
		graphic =
		{
			{	'.',	'.',	'.',	'.'	},
			{	'c',	'c',	'c',	'c'	},
			{	'.',	'.',	'.',	'.'	},
			{	'.',	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
				   (rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic	 =	{{	'.',	'.',	'.',	'.'	},
							{	'c',	'c',	'c',	'c'	},
							{	'.',	'.',	'.',	'.'	},
							{	'.',	'.',	'.',	'.'	}};
				break;

			case 1:
				graphic	 =	{{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	}};
				break;

			case 2:
				graphic	 =	{{	'.',	'.',	'.',	'.'	},
							{	'.',	'.',	'.',	'.'	},
							{	'c',	'c',	'c',	'c'	},
							{	'.',	'.',	'.',	'.'	}};
				break;

			case 3:
				graphic	 =	{{	'.',	'c',	'.',	'.'	},
							{	'.',	'c',	'.',	'.'	},
							{	'.',	'c',	'.',	'.'	},
							{	'.',	'c',	'.',	'.'	}};
				break;
		}
	}

protected:
private:
	int w = 4, h = 4;
};



class S_J : public Shape
{
public:
	S_J() : Shape(3, 3, 'b')
	{
		graphic = shape(3, vector<char>(3, '.'));
		graphic =
		{
			{	'b',	'.',	'.',	},
			{	'b',	'b',	'b',	},
			{	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
		(rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic =
				{
					{	'b',	'.',	'.',	},
					{	'b',	'b',	'b',	},
					{	'.',	'.',	'.'	}
				};
				break;

			case 1:
				graphic =
				{
					{	'.',	'b',	'b',	},
					{	'.',	'b',	'.',	},
					{	'.',	'b',	'.'	}
				};
				break;

			case 2:
				graphic =
				{
					{	'.',	'.',	'.',	},
					{	'b',	'b',	'b',	},
					{	'.',	'.',	'b'	}
				};
				break;

			case 3:
				graphic =
				{
					{	'.',	'b',	'.',	},
					{	'.',	'b',	'.',	},
					{	'b',	'b',	'.'	}
				};
				break;
		}
	}

protected:
private:
	int h = 3, w = 3;
};


class S_L : public Shape
{
public:
	S_L() : Shape(3, 3, 'o')
	{
		graphic = shape(3, vector<char>(3, '.'));
		graphic =
		{
			{	'.',	'.',	'o',	},
			{	'o',	'o',	'o',	},
			{	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
		(rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic =
				{
					{	'.',	'.',	'o',	},
					{	'o',	'o',	'o',	},
					{	'.',	'.',	'.'	}
				};
				break;

			case 1:
				graphic =
				{
					{	'.',	'o',	'.',	},
					{	'.',	'o',	'.',	},
					{	'.',	'o',	'o'	}
				};
				break;

			case 2:
				graphic =
				{
					{	'.',	'.',	'.',	},
					{	'o',	'o',	'o',	},
					{	'o',	'.',	'.'	}
				};
				break;

			case 3:
				graphic =
				{
					{	'o',	'o',	'.',	},
					{	'.',	'o',	'.',	},
					{	'.',	'o',	'.'	}
				};
				break;
		}
	}
protected:
private:
	int w = 3, h = 3;
};


class S_O : public Shape
{
public:
	S_O() : Shape(2, 2, 'y')
	{
		graphic = shape(2, vector<char>(2, '.'));
		graphic =	{{	'y',	'y'	},
					{	'y',	'y'	}};
	}

protected:
private:
	int w = 2, h = 2;
};


class S_S : public Shape
{
public:
	S_S() : Shape(3, 3, 'g')
	{
		graphic = shape(3, vector<char>(3, '.'));
		graphic =
		{
			{	'.',	'g',	'g',	},
			{	'g',	'g',	'.',	},
			{	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
		(rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic =
				{
					{	'.',	'g',	'g',	},
					{	'g',	'g',	'.',	},
					{	'.',	'.',	'.'	}
				};
				break;

			case 1:
				graphic =
				{
					{	'.',	'g',	'.',	},
					{	'.',	'g',	'g',	},
					{	'.',	'.',	'g'	}
				};
				break;

			case 2:
				graphic =
				{
					{	'.',	'.',	'.',	},
					{	'.',	'g',	'g',	},
					{	'g',	'g',	'.'	}
				};
				break;

			case 3:
				graphic =
				{
					{	'g',	'.',	'.',	},
					{	'g',	'g',	'.',	},
					{	'.',	'g',	'.'	}
				};
				break;
		}
	}

protected:
private:
	int w = 3, h = 3;
};


class S_T : public Shape
{
public:
	S_T() : Shape(3, 3, 'm')
	{
		graphic = shape(3, vector<char>(3, '.'));
		graphic =
		{
			{	'.',	'm',	'.',	},
			{	'm',	'm',	'm',	},
			{	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
				   (rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic =
				{
					{	'.',	'm',	'.',	},
					{	'm',	'm',	'm',	},
					{	'.',	'.',	'.'	}
				};
				break;

			case 1:
				graphic =
				{
					{	'.',	'm',	'.',	},
					{	'.',	'm',	'm',	},
					{	'.',	'm',	'.'	}
				};
				break;

			case 2:
				graphic =
				{
					{	'.',	'.',	'.',	},
					{	'm',	'm',	'm',	},
					{	'.',	'm',	'.'	}
				};
				break;

			case 3:
				graphic =
				{
					{	'.',	'm',	'.',	},
					{	'm',	'm',	'.',	},
					{	'.',	'm',	'.'	}
				};
				break;
		}
	}
protected:
private:
	int w = 3, h = 3;
};


class S_Z : public Shape
{
public:
	S_Z() : Shape(3, 3, 'r')
	{
		graphic = shape(3, vector<char>(3, '.'));
		graphic =
		{
			{	'r',	'r',	'.',	},
			{	'.',	'r',	'r',	},
			{	'.',	'.',	'.'	}
		};
	}

	void Rotate(int r)
	{
		rotation = (rotation + r == 4)	?	0	:
				   (rotation + r == -1)	?	3	:	rotation + r;

		switch(rotation)
		{
			case 0:
				graphic =
				{
					{	'r',	'r',	'.',	},
					{	'.',	'r',	'r',	},
					{	'.',	'.',	'.'	}
				};
				break;

			case 1:
				graphic =
				{
					{	'.',	'.',	'r',	},
					{	'.',	'r',	'r',	},
					{	'.',	'r',	'.'	}
				};
				break;

			case 2:
				graphic =
				{
					{	'.',	'.',	'.',	},
					{	'r',	'r',	'.',	},
					{	'.',	'r',	'r'	}
				};
				break;

			case 3:
				graphic =
				{
					{	'.',	'r',	'.',	},
					{	'r',	'r',	'.',	},
					{	'r',	'.',	'.'	}
				};
				break;
		}
	}
protected:
private:
	int w = 3, h = 3;
};



#endif /* Shape_hpp */
