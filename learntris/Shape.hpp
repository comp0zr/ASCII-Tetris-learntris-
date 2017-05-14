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

enum TYPE	{	I = 0,	T,    CROSS,	L1,	L2,	CUBE,	Z	};


class Shape
{
public:

	Shape()
	{
		graphic = shape(4, vector<char>(4, '.'));
		graphic =	{{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	},
					{	'.',	'.',	'.',	'.'	}};
	}
	Shape(int h_sz, int w_sz, char col) : h(h_sz), w(w_sz), color(col) {}

	void Display()
	{
		for(auto r : graphic)
		{PRINT_ARR(r, 0); std::cout << endl;}
	}
	virtual void Rotate() {};


protected:
	char color;
	int w, h;
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
		rotation += r;

		switch(rotation)
		{
			case 0:
				graphic	 =	{{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	},
							{	'.',	'.',	'c',	'.'	}};
				break;

			case 1:
				graphic	 =	{{	'.',	'.',	'.',	'.'	},
							{	'.',	'.',	'.',	'.'	},
							{	'c',	'c',	'c',	'c'	},
							{	'.',	'.',	'.',	'.'	}};
				break;
		}
	}

protected:


private:
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

};



#endif /* Shape_hpp */
