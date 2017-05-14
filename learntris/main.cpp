//
//  main.cpp
//  learntris
//
//  Created by Administrator on 5/13/17.
//
//

//#include <iostream>
#include "main.h"
#include "matrix.h"
#include "input.hpp"

InputParser IN;

int main(int argc, const char * argv[])
{
	Matrix M;
	char buffer[200];

	while(1)
	{
		int c = IN.Read(200);

		switch(IN.io)
		{
			case IO::GIVEN:
			{
				cin.clear();

				for(int i=0; i<22; i++)
				{
					cout << i << "| " << endl;
					cin.ignore();

					string s;
					getline(cin, s);

					int index = 0;
					for(auto c : s)
					{
						if(isalnum(c))
						{
							M.matrix[i][index] = c;
							index++;
						}
					}
					PRINT_ARR(M.matrix[i], 1);
					cerr << endl;
				}
				break;
				for(int i=0; i<22; i++)
				{
//					char* line;
					//= IN.Read((int)W_SIZE, ' ');

					for(int j=0; j<10; j++)
					{
						cin >> M.matrix[i][j];
						//M.matrix[i].assign(line, line + strlen(line));
					}
					PRINT_ARR(M.matrix[i], 1);
					cerr << endl;
				}
				break;
			}

			case IO::PRINT:
				M.Print();
				break;

			case IO::QUIT:
				exit(0);
				break;
		}

//		if(strcmp(buffer, "q") == 0)
//		{
//			exit(0);
//		}
//		else if(strcmp(buffer, "p") == 0)
//		{
//			M.Print();
//		}
//		else if(strcmp(buffer, "g") == 0)
//		{
//
//		}
	}
	return 0;
}
