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
 
    PhoneBook(void);
    ~PhoneBook(void);

    void        addContact(void);
    void        search(void) const;
    void        printCont(int i) const;
    int         getI(void) const;

};


#endif