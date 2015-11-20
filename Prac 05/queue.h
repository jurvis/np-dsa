//
//  queue.hpp
//  Prac05
//
//  Created by Jurvis Tan on 20/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef char ItemType;

class Queue {
private:
    struct Node {
        ItemType item;
        Node *next;
    };
    
    Node *frontNode;
    Node *backNode;
public:
    Queue();
    ~Queue();
    
    bool enqueue(const ItemType& newItem);
    bool dequeue();
    bool dequeue(ItemType& item);
    void getFront(ItemType& item);
    void displayItems();
    bool isEmpty();

};

#endif /* queue_h */
