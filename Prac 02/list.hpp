//
//  list.hpp
//  Practical 02
//
//  Created by Jurvis Tan on 29/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include "person.hpp"

const int MAX_SIZE = 100;
typedef Person ValueType;

class List {
private:
    ValueType
    items[MAX_SIZE];
    int size;
    
public:
    // Constructor
    List();
    
    bool add(const ValueType& newItem);
    bool insert(int index, const ValueType& newItem);
    ValueType get(int index) ;
    void remove(int index);
    int getLength();
};

#endif /* list_hpp */
