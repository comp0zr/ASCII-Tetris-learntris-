//
//  Shape.cpp
//  Tetris
//
//  Created by Administrator on 5/14/17.
//
//

#include "Shape.hpp"

#include <string>
#include <vector>
using namespace std;

typedef vector<vector<char>> shape;

class Shape
{
public:
	Shape(int h_sz, int w_sz, char col) : h(h_sz), w(w_sz), color(col) {}

	virtual void Rotate();

protected:
	char color;
	int w, h;
	shape graphic;

	int rotation = 0;
	vector<vector<pair<int, int>>> adj;
};


class S_I : protected Shape
{
public:
	S_I() : Shape(4, 4, 'c')
	{
		this->graphic = shape(4, vector<char>(4, '.'));
		graphic =
		{
			{	'.',		'.',		'.',		'.'		},
			{	color,	color,	color,	color	},
			{	'.',		'.',		'.',		'.'		},
			{	'.',		'.',		'.',		'.'		}
		};
	}

	void Rotate()
	{
		switch(rotation)
		{
			case 0:
				adj = {	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
						{{1, 0}, {1, 1}, {1, 2}, {1, 3}},
						{{2, 0}, {2, 1}, {2, 2}, {2, 3}},
						{{3, 0}, {3, 1}, {3, 2}, {3, 3}}	};
				break;

			case 1:
				adj = {	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
						{{0, 2}, {1, 2}, {2, 2}, {3, 2}},
						{{2, 0}, {2, 1}, {2, 2}, {2, 3}},
						{{3, 0}, {3, 1}, {3, 2}, {3, 3}}	};
				break;
		}
	}

protected:


private:
	int rotation = 0;
};

