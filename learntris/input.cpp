//
//  input.cpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//

#include "input.hpp"
using namespace std;


InputParser::InputParser()
{}


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


char* InputParser::Read(int maxSize, char delim)
{
	string input;
	std::getline(cin, input, delim);
	strcpy(buffer, input.c_str());
	cin.clear();
	return buffer;
}
