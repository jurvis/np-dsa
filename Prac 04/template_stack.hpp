//
//  template_stack.hpp
//  Prac04
//
//  Created by Jurvis Tan on 13/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef template_stack_hpp
#define template_stack_hpp

#include <stdio.h>

template <typename ValueType>
class T_Stack {
private:
    struct Node {
        ValueType item;
        Node *next;
    };
    Node *topNode;
    
public:
    T_Stack();
    ~T_Stack();
    
    bool isEmpty();
    bool push(const ValueType &item);
    bool pop();
    bool pop(ValueType &item);
    void getTop(ValueType &item);
    void displayInOrder();
    void displayInOrderOfInsertion();
};

template <typename ValueType>
T_Stack<ValueType>::T_Stack() {
    topNode = NULL;
}

// deconstructor
template <typename ValueType>
T_Stack<ValueType>::~T_Stack() {
    
}

template <typename ValueType>
bool T_Stack<ValueType>::isEmpty() {
    return topNode == NULL;
}

template <typename ValueType>
bool T_Stack<ValueType>::push(const ValueType &item) {
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    
    if (!isEmpty())
        newNode->next = topNode;
    topNode = newNode;
    return true;
}

template <typename ValueType>
bool T_Stack<ValueType>::pop() {
    bool success = false;
    if (!isEmpty()) {
        success = true;
        Node *temp = topNode;
        topNode = temp->next;
        
        temp->next = NULL;
        delete temp;
    }
    return success;
}

template <typename ValueType>
bool T_Stack<ValueType>::pop(ValueType &item) {
    getTop(item);
    return pop();
}

template <typename ValueType>
void T_Stack<ValueType>::getTop(ValueType &item) {
    item = -1;
    if (!isEmpty()) {
        item = topNode ->item;
    }
}


template <typename ValueType>
void T_Stack<ValueType>::displayInOrder() {
    Node *n = topNode;
    while (n != NULL) {
        std::cout << n->item << std::endl;
        n = n->next;
    }
}

template <typename ValueType>
void T_Stack<ValueType>::displayInOrderOfInsertion() {
    T_Stack<ValueType> *tmpStack = new T_Stack<ValueType>;
    
    while (!this->isEmpty()) {
        ValueType tmp = ' ';
        this->pop(tmp);
        tmpStack->push(tmp);
    }
    
    while (!tmpStack->isEmpty()) {
        ValueType tmp = ' ';
        tmpStack->pop(tmp);
        std::cout << tmp << std::endl;
        this->push(tmp);
    }
}

#endif /* template_stack_hpp */
