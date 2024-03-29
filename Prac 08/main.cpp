//
//  main.cpp
//  Prac08
//
//  Created by Jurvis Tan on 9/12/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "BST.h"
#include <string>
using namespace std;

void displayMenu();

int main(int argc, const char * argv[]) {
    BST bst;
    ItemType target;
    
    int dataArray[10] = { 55, 28, 87, 32, 90, 16, 45, 79, 66, 30 };
    
    for (int i=0; i<10; i++)
    {
        bst.insert(dataArray[i]);
    }
    
    int option = 1;
    
    while (option != 0)
    {
        displayMenu();
        cin >> option;
        
        if (option == 1)	// display items
            bst.inorder();
        else
            if (option == 2)	// search item
            {
                cout << "Enter a number to search : " ;
                cin >> target;
                BinaryNode* p = bst.search(target);
                if (p != NULL)
                    cout << "Found" << endl;
                else
                    cout << "Not found" << endl;
            }
            else
                if (option == 3)	// add item
                {
                    int n;
                    cout << "Enter a number to add : " ;
                    cin >> n;
                    bst.insert(n);
                }
                else
                    if (option == 4)	// delete item
                    {
                        int n;
                        cout << "Enter a number to delete : " ;
                        cin >> n;
                        bst.remove(n);
                    }
                    else
                    if (option == 5)	// display number of items
                        cout << bst.countNodes() << endl;
                    else
                    if (option == 6)	// display height
                        cout << bst.getHeight() << endl;
                    else
                        if (option == 7) {
                            string result = bst.isBalanced() ?"Tree is balanced!": "Tree is not balanced!";
                            cout << result << endl;
                        }
                    else
                    if (option == 0)
                        cout << "Bye! \n";
                    else
                        cout << "Sorry. You have entered an invalid option. \n";
    }
    return 0;
}

void displayMenu()
{
    cout << endl;
    cout << "Binary Search Tree Demo \n";
    cout << "--------------------------------\n";
    cout << "1 Display all the items in order\n";
    cout << "2 Search for an item \n";
    cout << "3 Add a new item \n";
    cout << "4 Delete an item \n";
    cout << "5 Display total number of items \n";
    cout << "6 Display the height \n";
    cout << "7 Check if tree is balanced \n";
    cout << "0 Exit \n";
    cout << "--------------------------------\n";
    cout << "Enter option : ";
}


