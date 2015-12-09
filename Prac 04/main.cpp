//
//  main.cpp
//  Prac04
//
//  Created by Jurvis Tan on 12/11/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "stack.h"
#include "template_stack.hpp"

int GetOperatorWeight(char c);
bool isOperand(char c);
bool isOperator(char c);
std::string convertInfixToPostFix(std::string exp);
int evaluatePostFixExp(std::string exp);
int performOperation(char operation, char operandA, char operandB);

int main(int argc, const char * argv[]) {
    T_Stack<char> *s = new T_Stack<char>;
    s->push('3');
    s->push('4');
    
    ItemType tmp;
    s->getTop(tmp);
    std::cout << "Top item of stack: " << tmp << std::endl;
    
    std::cout << "Displaying in order of insertion: " << std::endl;
    s->displayInOrderOfInsertion();
    
    s->pop();
    
    std::cout << "Displaying in order of insertion: " << std::endl;
    s->displayInOrderOfInsertion();
    
    std::string input;
    std::cout << "Enter infix operator: ";
    std::cin >> input;
    
    std::string postFix = convertInfixToPostFix(input);
    std::cout << postFix << std::endl;
    
    std::cout << evaluatePostFixExp(postFix) << std::endl;
    
    return 0;
}

int evaluatePostFixExp(std::string exp) {
    T_Stack<int> *valueStack = new T_Stack<int>;
    
    for (int i = 0; i < exp.length(); i++) {
        char nextChar = exp[i];
        if (nextChar == ' ') {
            continue;
        } else if (isOperand(nextChar)) {
            valueStack->push(nextChar - '0'); // trick to convert a char to int (e.g exp[i] = '2' evaluates to 50)
        } else if (isOperator(nextChar)) {
            int operandTwo;
            valueStack->pop(operandTwo);
            int operandOne;
            valueStack->pop(operandOne);
            double result = performOperation(nextChar, operandOne, operandTwo);
            valueStack->push(result);
        }
    }
    
    int result = 0;
    valueStack->getTop(result);
    return result;
}

int performOperation(char operation, char operandA, char operandB) {
    switch (operation) {
        case '+':
            return operandA + operandB;
            break;
        case '-':
            return operandA - operandB;
        case '*':
            return operandA * operandB;
        case '/':
            return operandA / operandB;
        case '^':
            return operandA ^ operandB;
        default:
            return 0.0;
            break;
    }
}

std::string convertInfixToPostFix(std::string exp) {
    Stack *operatorStack = new Stack;
    std::string postFix = "";
    
    for (int i = 0; i < exp.length(); i++) {
        char nextChar = exp[i];
        if (nextChar == ' ') {
            continue;
        } else if (isOperand(nextChar)) {
            postFix += exp[i];
        } else if (isOperator(nextChar)) {
            char tempChar;
            operatorStack->getTop(tempChar);
            while (!operatorStack->isEmpty() && GetOperatorWeight(nextChar) <= GetOperatorWeight(tempChar))  {
                postFix += tempChar;
                operatorStack->pop();
                operatorStack->getTop(tempChar);
            }
            operatorStack->push(nextChar);
        } else if (nextChar == '(') {
            operatorStack->push(nextChar);
        } else if (nextChar == ')') {
            char topOperator = ' ';
            operatorStack->getTop(topOperator);
            while (topOperator != '(') {
                postFix += topOperator;
                operatorStack->pop();
                operatorStack->getTop(topOperator);
            }
            operatorStack->pop();
        }
    }
    
    while (!operatorStack->isEmpty()) {
        char topOperator = ' ';
        operatorStack->getTop(topOperator);
        postFix += topOperator;
        operatorStack->pop();
    }
    
    return postFix;
}

int GetOperatorWeight(char c) {
    int weight = -1;
    switch (c) {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '^':
            weight = 3;
            break;
        default:
            break;
    }
    
    return weight;
}

bool isOperand(char c) {
    return isalnum(c);
}

bool isOperator(char c) {
    return (c == '^' || c == '+' || c == '-' || c == '*' || c == '/');

}