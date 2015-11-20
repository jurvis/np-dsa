//
//  main.cpp
//  Prac05
//
//  Created by Jurvis Tan on 20/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "stack.h"
#include <string>

bool IsPalindrome(std::string input);

int main(int argc, const char * argv[]) {
    // Question 5
    Queue *q = new Queue;
    q->enqueue('a');
    q->enqueue('b');
    
    ItemType c;
    q->getFront(c);
    std::cout << c << std::endl;
    
    q->displayItems();
    q->dequeue();
    q->displayItems();

    // Question 6
    std::cout << "==========Palindrome Checker==========" << std::endl;
    std::cout << "Enter string to check: " << std::endl;
    
    std::string input;
    std::cin >> input;
    
    if (IsPalindrome(input)) {
        std::cout << "String is palindrome!" << std::endl;
    }
    
    return 0;
}

bool IsPalindrome(std::string input) {
    Queue *tempQueue = new Queue;
    Stack *tempStack = new Stack;
    
    for (int i = 0 ; i < input.length(); i++) {
        char nextChar = input[i];
        tempQueue->enqueue(nextChar);
        tempStack->push(nextChar);
    }
    
    bool charactersAreEqual = true;
    while (!tempQueue->isEmpty()) {
        char tempQueueChar;
        tempQueue->getFront(tempQueueChar);
        char tempStackChar;
        tempStack->getTop(tempStackChar);
        
        if (tempQueueChar == tempStackChar) {
            tempQueue->dequeue();
            tempStack->pop();
        } else {
            charactersAreEqual = false;
            break;
        }
    }
    
    return charactersAreEqual;
}
