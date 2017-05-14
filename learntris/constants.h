#pragma once
//
//  constants.h
//  Tetris
//
//  Created by Administrator on 5/13/17.
//
//



#ifndef constants_h
#define constants_h


#define DEBUG 1

#if DEBUG
#define LOG(x) cerr<<x;
#else
#define LOG(x)
#endif

#define PRINT_ARR(arr, db) for(auto it : arr) {if(db) { cerr << it << ' '; } else{ cout << it << ' ';}};
#define ALL(iter) (iter.begin(), iter.end())

#define W_SIZE 10
#define H_SIZE 22
#define BLANK(x) string(x, '.')



#endif /* constants_h */
