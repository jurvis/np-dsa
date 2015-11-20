//
//  main.cpp
//  CalYearlySalary
//
//  Created by Jurvis Tan on 20/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#include <iostream>
#include "Employee.h"
#include <string>

int main(int argc, const char * argv[]) {
    
    Employee e1 = Employee("Duncan", "Leo", 3000);
    Employee e2 = Employee("Ivan", "Tan", 2000);
    
    std::cout << e1.getFirstName() << " " << e1.getLastName() << "'s Salary: " << e1.getMonthlySalary() << std::endl;
    std::cout << e2.getFirstName() << " " << e2.getLastName() << "'s Salary: " << e2.getMonthlySalary() << std::endl;
    
    e1.setMonthlySalary(e1.getMonthlySalary() * 1.1);
    e2.setMonthlySalary(e2.getMonthlySalary() * 1.1);

    std::cout << "Display Salaries after 10% increment..." << std::endl;
    std::cout << e1.getFirstName() << " " << e1.getLastName() << "'s Salary: " << e1.getMonthlySalary() << std::endl;
    std::cout << e2.getFirstName() << " " << e2.getLastName() << "'s Salary: " << e2.getMonthlySalary() << std::endl;
    
    
    return 0;
}
