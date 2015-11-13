//
//  person.cpp
//  Practical 02
//
//  Created by Jurvis Tan on 29/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include "person.hpp"
#include <string>

Person::Person() {
    
}

Person::Person(std::string person_name, std::string person_tel) {
    name = person_name;
    tel = person_tel;
}

std::string Person::getName() {
    return name;
}

void Person::setName(std::string person_name) {
    name = person_name;
}

std::string Person::getTelNo() {
    return tel;
}

void Person::setTelNo(std::string person_tel) {
    tel = person_tel;
}