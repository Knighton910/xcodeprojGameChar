//
//  GameChar.cpp
//  GameChar
//
//  Created by Brian Pang on 4/23/15.
//  Copyright (c) 2015 Brian Pang. All rights reserved.
//

#include <stdio.h>
#include "GameChar.h"

using namespace std;

// constructor
GameChar::GameChar(std::string newName, int cap)
{
    cout << " * 1 GameChar::GameChar(std::string newName, int cap) constructor called from " << newName << endl;
    this->name = newName;
    this->capacity = cap;
    this->used = 0;
    this->pToolHolder = new string[DEFAULT_CAPACITY];

}

// copy constructor
GameChar::GameChar(const GameChar& source)
{
    cout << " * 2 GameChar::GameChar(const GameChar& source) Copy constructor called from " << source.name << endl;
    this->name = source.name;
    this->capacity = source.capacity;
    this->used = source.used;
    this->pToolHolder = new string[source.capacity];
    //copy(source.pToolHolder, source.pToolHolder + this->used, pToolHolder);  // copy template library
    // do my own copy instead of using the copy in the library template.
    for(int i=0; i < this->used; ++i)  {
        pToolHolder[i] = source.pToolHolder[i];
    }
}

//overloaded assignment operator
GameChar& GameChar::operator=(const GameChar& source)
{
    cout << " * 3 Overloaded assignment operator= called from " << source.name  << endl;
    
    // check for self assignment, to prevent gc1=gc1, it will return *this;
    if (this != &source)  {
        this->name = source.name;
        this->capacity = source.capacity;
        this->used = source.used;
        //copy(source.pToolHolder, source.pToolHolder+this->used, this->pToolHolder);
        // Do the copy yourself instead of using the copy in the template library
        for(int i=0; i < this->used; ++i)  {
            pToolHolder[i] = source.pToolHolder[i];
        }
    }    
    return *this;
}

// destructor
GameChar::~GameChar()
{
    cout << " * 4 destructor called for " << this->name << " @ this memory location " << this << endl;
    delete [] pToolHolder;
    
}

// insert a new tool into our pToolHolder
void GameChar::insert(const string& toolName)
{
    if (this->used == this->capacity)
    {
        cout << "     Tool Holder is full.  Cannot add additional tool: " << toolName  << endl;
    }
    else {
        pToolHolder[this->used] = toolName;
        this->used++;
        cout << "     Insert( " << toolName << " )" << endl;
    }
}

std::ostream& operator<<(std::ostream& os, const GameChar& gc)
{
    os << "     Game Char " << gc.name << "\n     has the following tools: " << std::endl << "     | ";
    for (int i=0; i< gc.used; i++)
    {
        os << gc.pToolHolder[i] + " | ";
    }
    return os << std::endl;
}