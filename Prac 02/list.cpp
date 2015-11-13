//
//  list.cpp
//  Practical 02
//
//  Created by Jurvis Tan on 29/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include "list.hpp"

// constructor
List::List()
{
    size = 0;
}

bool List::add(const ValueType& newItem) {
    return insert(size + 1, newItem);
}

bool List::insert(int index, const ValueType& newItem){
    bool success = (index >= 1) && (index <= size + 1) && (size < MAX_SIZE);
    if (success)
    {  // make room for new item by shifting all items at
        // positions >= index toward the end of the
        // List (no shift if index == size + 1)
        for (int pos = size; pos >= index; pos--)
            items[pos] = items[pos-1];
        // insert new item
        items[index-1] = newItem;
        size++;  // increase the size of the list by one
    }
    return success;
}

ValueType List::get(int index) {
    ValueType* dataItem = NULL;
    bool success = (index >= 1) && (index <= size);
    if (success)
        dataItem = &items[index - 1];
    
    return *dataItem;
}

void List::remove(int index) {
    bool success = (index >= 1) && (index <= size);
    if (success)
    {  // delete item by shifting all items at positions >
        // index toward the beginning of the list
        // (no shift if index == size)
        for (int fromPosition = index + 1; fromPosition <= size; fromPosition++)
            items[fromPosition - 2] = items[fromPosition - 1];
        size--;  // decrease the size of the list by one
    }
    
}
int List::getLength() {
    return size;
}
