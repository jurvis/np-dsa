//
//  list.hpp
//  Lecture 03
//
//  Created by Jurvis Tan on 3/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <iostream>

typedef std::string ItemType;

class List {

private:
    struct Node {
        ItemType item;
        Node *next;
    };
    
    Node *first_node;
    int size;
    
public:
    List();
    
    bool add(ItemType new_item);
    bool add(int index , ItemType item);
    void remove(int index);
    ItemType get(int index);
    bool isEmpty();
    int getLength();
    void print();
};

#endif /* list_hpp */
