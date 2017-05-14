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
#include <deque>

enum class IO
{
//	MAIN COMMANDS

	CLEAR = 'c',
	DISPLAY_ACTIVE = 't',
	GIVEN = 'g',
	LINES = 'l',
	NEWLINE = ';',
	PRINT = 'p',
	PRINT_WITH_ACTIVE = 'P',
	QUIT = 'q',
	ROTATE_CLOCKWISE = ')',
	ROTATE_COUNTER = '(',
	SCORE = 's',
	STEP = '&',

//	SHAPE TYPES

	SHAPE_I = 'I',
	SHAPE_J = 'J',
	SHAPE_L = 'L',
	SHAPE_T = 'T',
	SHAPE_O = 'O',
	SHAPE_S = 'S',
	SHAPE_Z = 'Z'
};

static std::map<std::string, IO> commands =
{
	{	"c",		IO::CLEAR				},
	{	"g",		IO::GIVEN				},
	{	";",		IO::NEWLINE			},
	{	"I",		IO::SHAPE_I				},
	{	"J",		IO::SHAPE_J				},
	{	"L",		IO::SHAPE_L				},
	{	"O",		IO::SHAPE_O			},
	{	"S",		IO::SHAPE_S				},
	{	"T",		IO::SHAPE_T				},
	{	"Z",		IO::SHAPE_Z				},
	{	"?n",	IO::LINES				},
	{	"p",		IO::PRINT				},
	{	"P",		IO::PRINT_WITH_ACTIVE	},
	{	"q",		IO::QUIT				},
	{	")",		IO::ROTATE_CLOCKWISE },
	{	"(",		IO::ROTATE_COUNTER	},
	{	"?s",		IO::SCORE				},
	{	"s",		IO::STEP					},
	{	"t",		IO::DISPLAY_ACTIVE		}
};



class InputParser
{
public:

	InputParser();

	int Read(int maxSize);
	char* ReadLine(int maxSize, char delim);
	char* Read();

	char buffer[200];
	std::deque<char*> command_queue;

	IO io;
};


#endif /* input_hpp */
