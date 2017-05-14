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

	virtual void Rotate(int r) {};


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
				graphic	 =	{{	'.',	'c',	'.',	'.'},
							{	'.',	'c',	'.',	'.'},
							{	'.',	'c',	'.',	'.'},
							{	'.',	'c',	'.',	'.'}};
				break;
		}
	}

protected:
private:
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
};



#endif /* Shape_hpp */
