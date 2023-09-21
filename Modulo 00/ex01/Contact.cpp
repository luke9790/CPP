#include <iostream>
#include <string>
#include "./Contact.hpp"

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

static void    ft_fill_line(std::string out, std::string *in)
{
    std::string tmp;

    std::cout << out;
    while (std::getline(std::cin, tmp) && !tmp[0])
    {
        std::cout << "No empty fields!" << std::endl << out;
    }
    *in = tmp;
}

static int         ft_is_phonenumber(std::string pn)
{
    int i;
    
    for (i = 0; pn[i]; i++)
    {
        if (!std::isdigit(pn[i]))
        {
            std::cout << "Please enter a valid number (only digits allowed)" << std::endl;
            return (false);
        }
    }
    return (true);
}

void        Contact::init(int i)
{
    std::string tmp_num;
    
    this->Index = i;
    ft_fill_line("Firstname: ", &this->FirstName);
    ft_fill_line("Lastname: ", &this->LastName);
    ft_fill_line("Nickname: ", &this->Nickname);
    ft_fill_line("Number: ", &tmp_num);
    while (!ft_is_phonenumber(tmp_num))
        ft_fill_line("Number: ", &tmp_num);
    this->PhoneNumber = tmp_num;
    ft_fill_line("Darkest secret: ", &this->DarkestSecret);
}

int         Contact::GetIndex(void) const
{
    return (this->Index);
}

std::string Contact::GetFirstName(void) const
{
    return (this->FirstName);
}

std::string Contact::GetLastName(void) const
{
    return (this->LastName);
}

std::string Contact::GetNickname(void) const
{
    return (this->Nickname);
}

std::string Contact::GetPhoneNumber(void) const
{
    return (this->PhoneNumber);
}

std::string Contact::GetDarkestSecret(void) const
{
    return (this->DarkestSecret);
}