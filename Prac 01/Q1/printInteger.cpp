//
//  main.cpp
//  PrintDigits
//
//  Created by Jurvis Tan on 19/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void PrintDigits(int i);

int main(int argc, const char * argv[]) {
    int i;
    cout << "Enter Integer: ";
    cin >> i;

    PrintDigits(i);

    return 0;
}


void PrintDigits(int i) {
    if (i / 10 > 0) {
        PrintDigits(i / 10);
    }

    cout << i % 10 << "   ";
}
