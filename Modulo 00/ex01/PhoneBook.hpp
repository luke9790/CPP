#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "./Contact.hpp"

class PhoneBook
{
private:

    Contact contatto[8];
    static int  i;

public:
 
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void search() const;
    void printCont(int i) const;
    int  getI() const;

};


#endif