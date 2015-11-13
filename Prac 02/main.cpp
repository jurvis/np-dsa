//
//  main.cpp
//  Practical 02
//
//  Created by Jurvis Tan on 27/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "person.hpp"
#include "list.hpp"

List listOfContacts;

int displayMenu();
void listPhoneNumbers();
void displayAddNewContact();
void displayRemoveContact();
void displaySearchForNumber();

int main(int argc, const char * argv[]) {
    bool checker = false;
    
    while (checker == false) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                listPhoneNumbers();
                break;
            case 2:
                displayAddNewContact();
                break;
            case 3:
                displayRemoveContact();
                break;
            case 4:
                displaySearchForNumber();
                break;
            default:
                checker = true;
                break;
        }
    }
    
    return 0;
}

int searchForNumberWithName(std::string name) {
    int returnIndex = -1;
    
    for (int i = 1; i <= listOfContacts.getLength(); i++) {
        Person p = listOfContacts.get(i);
        if (p.getName().compare(name) == 0) // for whatever reason regular string comparison ignores whitespace characters
        {
            returnIndex = i;
            break;
        }
    }
    
    return returnIndex;
}

void displaySearchForNumber() {
    std::string nameToSearchFor;
    if (listOfContacts.getLength() == 0) {
        std::cout << "No contacts to search for" << std::endl;
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter person's name to search for: ";
    std::getline(std::cin, nameToSearchFor);
    
    int searchedIndex = searchForNumberWithName(nameToSearchFor);
    if ( searchedIndex > -1) {
        Person p = listOfContacts.get(searchedIndex);
        std::cout << searchedIndex << ". " << "[" << p.getName() << "] -> " << p.getTelNo() << std::endl;
    } else {
        std::cout << "Person not found" << std::endl;
    }
    
}

void displayRemoveContact() {
    listPhoneNumbers();
    if (listOfContacts.getLength() == 0) {
        std::cout << "No contacts to remove" << std::endl;
        return;
    }
    
    int indexToRemove;
    
    std::cout << "Enter number in list to remove: ";
    std::cin >> indexToRemove;
    listOfContacts.remove(indexToRemove);
    std::cout << "Number removed!" << std::endl;
}

void displayAddNewContact() {
    std::string name;
    std::string telNo;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, telNo);
    
    Person *newPersonPtr;
    Person personValue = Person(name, telNo);
    newPersonPtr = &personValue;
    listOfContacts.add(*newPersonPtr);
    
    std::cout << "Contact Added!" << std::endl;
}

void listPhoneNumbers() {
    int listLength = listOfContacts.getLength();
    if (listLength == 0) {
        std::cout << "No numbers in store" << std::endl;
        return;
    }
    
    
    for (int i = 1; i <= listOfContacts.getLength(); i++) {
        Person p = listOfContacts.get(i);
        std::cout << i << ". " << "[" << p.getName() << "] -> " << p.getTelNo() << std::endl;
    }
}

int displayMenu() {
    int selectedInput;
    
    std::cout << "---------------- Main Menu -------------------" << std::endl
            << "[1]     List the phone numbers" << std::endl
            << "[2]     Add a new contact" << std::endl
            << "[3]     Remove a contact" << std::endl
            << "[4]     Search for a phone number" << std::endl
            << "[0]     Exit" << std::endl
            << "----------------------------------------------" << std::endl;
    std::cout << "Enter your option: ";
    
    std::cin >> selectedInput;
    return selectedInput;
}
