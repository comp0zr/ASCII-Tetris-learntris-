//
//  input.cpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//

//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <strings.h>



#include "input.hpp"
//#include "main.h"

using namespace std;


InputParser::InputParser()
{}

//cmd<IO>
int InputParser::Read(int maxSize)
{
	do
	{
		cin.get(buffer, maxSize);
		cin.ignore(1, '\n');

	} while(commands.count(buffer) == 0);

	cin.clear();
	io = commands[buffer];
	return (int)commands[buffer];
}

//cmd<char*>
char* InputParser::Read(int maxSize, char delim)
{
	string input;
	std::getline(cin, input, delim);
	strcpy(buffer, input.c_str());
	cin.clear();
	return buffer;
}

//char* InputParser::Read(int values)
//{
//	cin >> buffer;
//	return buffer;
//}
