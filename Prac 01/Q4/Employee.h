//
//  Employee.hpp
//  CalYearlySalary
//
//  Created by Jurvis Tan on 20/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

#include <iostream>

class Employee {
    
public:
    Employee (std::string, std::string, int);
    std::string getFirstName();
    std::string getLastName();
    int getMonthlySalary();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setMonthlySalary(int);
    
private:
    std::string firstName;
    std::string lastName;
    int monthlySalary;
};

#endif /* Employee_h */
