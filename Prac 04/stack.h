//
//  stack.hpp
//  Prac04
//
//  Created by Jurvis Tan on 12/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>

typedef char ItemType;

class Stack {
private:
    struct Node {
        ItemType item;
        Node *next;
    };
    
    Node *topNode;
public:
    Stack();
    ~Stack();
    
    bool isEmpty();
    bool push(const ItemType &item);
    bool pop();
    bool pop(ItemType &item);
    void getTop(ItemType &item);
    void displayInOrder();
    void displayInOrderOfInsertion();
};

#endif /* stack_h */
