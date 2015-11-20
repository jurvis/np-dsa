//
//  queue.cpp
//  Prac05
//
//  Created by Jurvis Tan on 20/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "queue.h"

Queue::Queue() {
    frontNode = NULL;
    backNode = NULL;
}

bool Queue::enqueue(const ItemType &newItem) {
    Node *new_node = new Node;
    new_node->item = newItem;
    new_node->next = NULL;
    
    if (isEmpty()) {
        frontNode = new_node;
    } else {
        backNode->next = new_node;
    }
    
    backNode = new_node;
    return true;
}

bool Queue::dequeue() {
    Node *tempPtr;
    if (frontNode == backNode) {
        tempPtr = frontNode;
        frontNode = NULL;
        backNode = NULL;
    } else {
        tempPtr = frontNode;
        frontNode = tempPtr->next;
    }
    
    tempPtr->next = NULL;
    delete tempPtr;
    
    return true;
}

bool Queue::dequeue(ItemType &item) {
    Node *tempPtr;
    if (frontNode == backNode) {
        tempPtr = frontNode;
        frontNode = NULL;
        backNode = NULL;
    } else {
        tempPtr = frontNode;
        frontNode = tempPtr->next;
    }
    
    item = tempPtr->item;
    tempPtr->next = NULL;
    delete tempPtr;
    
    return true;
}

void Queue::getFront(ItemType &item) {
    if (!isEmpty()) {
        item = frontNode->item;
    }
}

void Queue::displayItems() {
    Node *n = frontNode;
    while (n != NULL) {
        std::cout << n->item <<std::endl;
        n = n->next;
    }
}

bool Queue::isEmpty() {
    return frontNode == NULL && backNode == NULL;
}
