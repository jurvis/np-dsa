//
//  main.cpp
//  PointerDemo
//
//  Created by Jurvis Tan on 20/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void changeValue(int x, int *y);

int main(int argc, const char * argv[]) {
    int x = 30;
    int y;
    y = x;
    changeValue(x, &y);
    
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}


void changeValue(int x, int *y) {
    
    x += 10;
    *y += 10;
}

