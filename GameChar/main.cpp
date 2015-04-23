//
//  main.cpp
//  GameChar
//
//  Created by Brian Pang on 4/23/15.
//  Copyright (c) 2015 Brian Pang. All rights reserved.
//

#include <iostream>
#include "GameChar.h"

using namespace std;

GameChar exCopyConstructor(GameChar tempGC)
{
    cout << " * exCopyConstructor() called. Copy constructor called twice" << endl;
    //cout << "exCopyConstructor() called. Once for the formal parameter being passed by value" << endl;
    //cout << "exCopyConstructor() called. Once for the return value." << endl;
    return tempGC;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    GameChar gc1;
    gc1.insert("potion");
    gc1.insert("crossbow");
    gc1.insert("candle");
    gc1.insert("cloak");
    gc1.insert("sword");
    gc1.insert("book of spells");
    cout << gc1 << endl;
    
    GameChar gc2("Jane", 5);
    gc2.insert("axe");
    exCopyConstructor(gc2);
    
    GameChar gc3 = gc2;
    
    // overloaded assignment operator
    gc2= gc1;
    
    cout << "gc2: " << gc2 << endl;
    cout << "gc1: " << gc1 << endl;
    cout << "gc3: " << gc3 << endl;
    
    return 0;
}
