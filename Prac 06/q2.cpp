//
//  main.cpp
//  Prac06_02
//
//  Created by Jurvis Tan on 26/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

int maxArray(const int anArray[], int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    int intArray[5] = {3, 17, 5, 24, 1};
    std::cout << "Max value in array is: " << maxArray(intArray, 5) << std::endl;
    return 0;
}

int maxArray(const int anArray[], int n) {
    n--;
    if (n == 0) {
        return anArray[n];
    } else {
        return std::max(anArray[n], maxArray(anArray, n - 1));
    }
}
