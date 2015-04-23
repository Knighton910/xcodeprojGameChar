//
//  GameChar.h
//  GameChar
//
//  Created by Brian Pang on 4/23/15.
//  Copyright (c) 2015 Brian Pang. All rights reserved.
//

#ifndef GameChar_GameChar_h
#define GameChar_GameChar_h

#include <iostream>
#include <string>

class GameChar
{
    friend std::ostream& operator<<(std::ostream& os, const GameChar& gc);
    
public:
    static const int DEFAULT_CAPACITY=5;
    
    // constructor
    GameChar(std::string name="Brian", int capacity=DEFAULT_CAPACITY);
    
    // copy constructor
    GameChar(const GameChar& source);
    
    // overloaded assignment
    GameChar& operator=(const GameChar& source);
    
    // destructor
    ~GameChar();
    
    // insert a new tool into the tool holder
    void insert(const std::string& toolName);

private:
    // data members
    std::string name;
    int capacity;
    int used;
    std::string* pToolHolder;
    
};

#endif
