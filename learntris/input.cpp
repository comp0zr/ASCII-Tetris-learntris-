//
//  input.cpp
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//

#include <sstream>
#include "input.hpp"
#include "constants.h"

using namespace std;


InputParser::InputParser()
{}


int InputParser::Read(int maxSize)
{
	int in;

	do
	{
		in = cin.get();
		*buffer = (char)in;
//		cin.get(buffer, maxSize);
//		cin.ignore(1, '\n');
	} while(!isspace(in));
	//while(commands.count(buffer) == 0);

	cin.clear();
	io = commands[buffer];

	if(commands.count(buffer)) return (int)commands[buffer];

	LOG("Invalid input. Please try again: ");
	return -1;
//	return (int)commands[buffer];
}


char* InputParser::ReadLine(int maxSize, char delim)
{
	string input;
	std::getline(cin, input, delim);
	strcpy(buffer, input.c_str());
	cin.clear();
	return buffer;
}

char* InputParser::Read()
{
	
//	cin.get(buffer, 200, isspace());

//	cin.clear();
	string input;
	std::getline(cin, input);
//	cin.ignore();

//	char* substring;
	stringstream ss;

	for(auto c : input)
	{
		if(isspace(c) || commands.count(ss.str()) != 0)
		{
			if(ss.str().length() == 0) continue;

			command_queue.push_back((char*)ss.str().c_str());
			ss.clear();
			continue;
		}
		ss << c;
	}
	if(ss.str().length() > 0) command_queue.push_back((char*)ss.str().c_str());

	for(auto it : command_queue) LOG(it << endl);

	return buffer;
}
