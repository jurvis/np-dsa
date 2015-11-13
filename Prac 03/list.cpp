//
//  list.cpp
//  Lecture 03
//
//  Created by Jurvis Tan on 3/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <string>
#include "list.hpp"

List::List() {
    size = 0;
}

bool List::add(ItemType new_item) {
    Node *new_node = new Node();
    new_node->item = new_item;
    new_node->next = NULL;
    
    if (size == 0) {
        first_node = new_node;
    } else {
        Node *n = first_node;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = new_node;
    }
    
    size++;
    return true;
}

bool List::add(int index , ItemType item) {
    int realIndex = index - 1;
    if (realIndex >= 0 && realIndex <= size) {
        Node *n = new Node;
        n->item = item;
        n->next = NULL;
        
        if (realIndex == 0) {
            n->next = first_node;
            first_node = n;
        } else {
            Node *tempNode = first_node;
            for (int i = 0; i < realIndex - 1; i++) {
                tempNode = tempNode->next;
            }
            Node *after = tempNode->next;
            tempNode->next = n;
            n->next = after;
        }
        size++;
        return true;
    }
    else {
        return false;
    }
}

void List::remove(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            Node *tempNode = first_node->next;
            first_node = tempNode;
        } else {
            Node *tempNode = first_node;
            for(int i = 1; i < index - 1; i++) {
                tempNode = tempNode ->next;
            }
            Node *nextNode = tempNode->next->next;
            tempNode->next = nextNode;
        }
        size--;
    }
}

ItemType List::get(int index) {
    ItemType result = NULL;
    if (index > 1 && index <= size) {
        Node *tempNode = first_node;
        for (int i = 1; i < index - 1; i++) {
            tempNode = tempNode->next;
        }
        result = tempNode->item;
    }
    return result;
}

bool List::isEmpty() {
    return size == 0;
}

int List::getLength() {
    return size;
}

void List::print() {
    Node *n = first_node;
    while (n!= NULL) {
        std::cout << n->item << std::endl;
        n = n->next;
    }
}


