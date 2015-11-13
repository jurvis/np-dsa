//
//  Employee.cpp
//  CalYearlySalary
//
//  Created by Jurvis Tan on 20/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include "Employee.h"
#include <string>

Employee::Employee(std::string fn, std::string ln, int s) {
    firstName = fn;
    lastName = ln;
    monthlySalary = (s < 0) ? 0: s;
}

std::string Employee::getFirstName() {
    return firstName;
}

std::string Employee::getLastName() {
    return lastName;
}

int Employee::getMonthlySalary() {
    return monthlySalary;
}

void Employee::setFirstName(std::string s) {
    firstName = s;
}

void Employee::setLastName(std::string s) {
    lastName = s;
}

void Employee::setMonthlySalary(int n) {
    monthlySalary = n;
}
