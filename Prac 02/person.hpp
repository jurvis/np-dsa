//
//  person.hpp
//  Practical 02
//
//  Created by Jurvis Tan on 29/10/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <string>

class Person {
private:
    std::string name;
    std::string tel;
    
public:
    Person();
    Person(std::string person_name, std::string person_tel);
    
    void setName(std::string person_name);
    std::string getName();
    void setTelNo(std::string person_tel);
    std::string getTelNo();
};

#endif /* person_hpp */
