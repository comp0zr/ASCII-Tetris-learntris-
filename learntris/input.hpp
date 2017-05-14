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
	GIVEN = 'g',
	PRINT = 'p',
	QUIT = 'q'
};

static std::map<std::string, IO> commands =
{
	{("g"), IO::GIVEN}, {("p"), IO::PRINT}, {("q"), IO::QUIT}
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
