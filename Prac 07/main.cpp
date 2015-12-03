//
//  main.cpp
//  Practical 07
//
//  Created by Jurvis Tan on 1/12/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include <string>

static int comparisons = 0;
int search(int dataArray[], int arraySize, int target);
int binarySearch(int dataArray[], int arraySize, int target);
int recSearch(int dataArray[], int arraySize, int target);
int recBinarySearch(int dataArray[], int first, int last, int target);

int main(int argc, const char * argv[]) {
    int dataArray[1000];
    for (int i = 1; i <= 1000; i++) {
        dataArray[i-1] = i * 2;
    }
    std::cout << "Enter number to search for: ";
    int input;
    std::cin >> input;
    
    if (search(dataArray, 1000, input) != -1) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }
    
    comparisons = 0;
    int idx1 = search(dataArray, 1000, input);
    std::cout << "Sequential Search: " << comparisons << std::endl;
    
    comparisons = 0;
    int idx2 = binarySearch(dataArray, 1000, input);
    std::cout << "Binary Search: " << comparisons << std::endl;
    
    return 0;
}

int search(int dataArray[], int arraySize, int target) {
    int index = 0;
    
    while (index != arraySize - 1) {
        comparisons++;
        if (target == dataArray[index]) {
            return index;
        } else if (dataArray[index] > target) {
            break;
        } else {
            index++;
        }
    }
    return -1;
}

int binarySearch(int dataArray[], int arraySize, int target) {
    int start = 0;
    int last = arraySize - 1;
    
    while (start <= last) {
        comparisons++;
        int mid = (start + last) / 2;
        if (dataArray[mid] == target) {
            return mid;
        } else if (target < dataArray[mid]) {
            last = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return -1;
}


int recSearch(int dataArray[], int arraySize, int target) {
    if (arraySize < 0) { // cannot be found
        return - 1;
    } else if (dataArray[arraySize - 1] == target) {
        return 1;
    } else {
        return recSearch(dataArray, arraySize - 1, target);
    }
}

int recBinarySearch(int dataArray[], int first, int last, int target) {
    if (first > last) return - 1; // there are no elements in the active part of the array
    int mid = (first + last) / 2;
    if (dataArray[mid] == target) return mid;
    
    if (dataArray[mid] > target) {
        return recBinarySearch(dataArray, first, mid - 1, target);
    } else {
        return recBinarySearch(dataArray, mid + 1, last, target);
    }
}
