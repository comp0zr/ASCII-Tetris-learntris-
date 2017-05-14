//
//  input.hpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//
#pragma once

#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>

enum class IO
{
	CLEAR = 'c',
	GIVEN = 'g',
	LINES = 'l',
	PRINT = 'p',
	QUIT = 'q',
	SCORE = 's',
	STEP = 'S'
};

static std::map<std::string, IO> commands =
{
	{	("c"),	IO::CLEAR	},
	{	("g"), 	IO::GIVEN	},
	{	("?n"),	IO::LINES	},
	{	("p"),	IO::PRINT	},
	{	("q"),	IO::QUIT	},
	{	("?s"),	IO::SCORE	},
	{	("s"),	IO::STEP		}
};


//template <class T>
//class cmd
//{
//	T data;
//
//public:
//	cmd (T arg) {		data = arg;	  }
//};




class InputParser
{
public:

	InputParser();

	int Read(int maxSize);
	char* Read(int maxSize, char delim);
//	void Read(int values);
	

	char buffer[200];
	IO io;
};


#endif /* input_hpp */
