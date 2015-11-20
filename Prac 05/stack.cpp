//
//  stack.cpp
//  Prac04
//
//  Created by Jurvis Tan on 12/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include "stack.h"
#include <iostream>


Stack::Stack() {
    topNode = NULL;
};

//deconstructor
Stack::~Stack() {
    
}

bool Stack::isEmpty() {
    return topNode == NULL;
};

bool Stack::push(const ItemType &item) {
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    
    if (!isEmpty())
        newNode->next = topNode;
    topNode = newNode;
    return true;
};

bool Stack::pop() {
    bool success = false;
    if (!isEmpty()) {
        success = true;
        Node *temp = topNode;
        topNode = temp->next;
        
        temp->next = NULL;
        delete temp;
    }
    return success;
};

bool Stack::pop(ItemType &item) {
    getTop(item);
    return pop();
}

void Stack::getTop(ItemType &item) {
    item = -1;
    if (!isEmpty()) {
        item = topNode->item;
    }
};