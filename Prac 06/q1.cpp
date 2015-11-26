//
//  main.cpp
//  Prac06_1
//
//  Created by Jurvis Tan on 26/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include <string>

long power(int a, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Enter Base: ";
    int baseInput;
    std::cin >> baseInput;
    std::cout << "Enter Power: ";
    int powerInput;
    std::cin >> powerInput;
    std::cout << "The result is: " << power(baseInput, powerInput) << std::endl;
    
    return 0;
}

long power(int a, int n) {
    if (n == 1) {
        return a;
    } else {
        return (a * power(a, n -1));
    }
}