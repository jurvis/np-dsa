//
//  main.cpp
//  Practical 03
//
//  Created by Jurvis Tan on 4/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "list.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    List *nameList = new List;
    nameList->add("Annie");
    nameList->add("Jacky");
    nameList->add("Wendy");
    nameList->print();
    std::cout << "====================" << std::endl;
    nameList->add(2, "Brenda");
    nameList->print();
    std::cout << "====================" << std::endl;
    nameList->remove(3);
    nameList->print();
    std::cout << "====================" << std::endl;
    nameList->remove(1);
    nameList->print();
    return 0;
}
