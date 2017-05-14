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
//	MAIN COMMANDS

	CLEAR = 'c',
	DISPLAY_ACTIVE = 't',
	GIVEN = 'g',
	LINES = 'l',
	PRINT = 'p',
	QUIT = 'q',
	SCORE = 's',
	STEP = 'S',

//	SHAPE TYPES

	SHAPE_I = 'I',
	SHAPE_O = 'O'
};

static std::map<std::string, IO> commands =
{
	{	"c",		IO::CLEAR				},
	{	"g",		IO::GIVEN				},
	{	"I",		IO::SHAPE_I				},
	{	"O",		IO::SHAPE_O			},
	{	"?n",	IO::LINES				},
	{	"p",		IO::PRINT				},
	{	"q",		IO::QUIT				},
	{	"?s",		IO::SCORE				},
	{	"s",		IO::STEP					},
	{	"t",		IO::DISPLAY_ACTIVE		}
};

/*
//template <class T>
//class cmd
//{
//	T data;
//
//public:
//	cmd (T arg) {		data = arg;	  }
//};
*/

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
