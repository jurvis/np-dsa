//
//  pointerDemo2.cpp
//  PointerDemo
//
//  Created by Jurvis Tan on 20/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
using namespace std;

int pd_main(int argc, const char * argv[]) {
    long value1 = 200000;
    long value2;
    long *longPtr = &value1;
    
    cout << *longPtr << endl;
    value2 = *longPtr;
    cout << value2 << endl;
    
    cout << "Address of value1: " << &value1 << endl;
    cout << "Address of longPtr: " << &longPtr << endl;
    longPtr = &value2;
    *longPtr += 2000;
    
    cout << "Value of value1: " << value1 << endl;
    cout << "Value of value2: " << value2 << endl;
    
    return 0;
}
