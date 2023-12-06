#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    int         Index;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    Contact();
    ~Contact();

    void        init(int i);
    int         GetIndex(void) const;
    std::string GetFirstName(void) const;
    std::string GetLastName(void) const;
    std::string GetNickname(void) const;
    std::string GetPhoneNumber(void) const;
    std::string GetDarkestSecret(void) const;
};



#endif