#include <iostream>
#include <string>
#include "./PhoneBook.hpp"

int PhoneBook::i = 0;

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook() 
{
}

void PhoneBook::addContact(void)
{
    if(this->i >= 8)
        std::cout << "Attention: this contact will replace an existing one" << std::endl;
    this->contatto[this->i % 8].init((this->i % 8) + 1);
    this->i++;
}

void ft_print_string(std::string s)
{
    if (s.length() < 10)
    {
        for (int i = 10 - s.length(); i; i--)
            std::cout << " ";
        std::cout << s;
    }
    else
        std::cout << s.substr(0, 9) << ".";
}

void PhoneBook::search(void) const {
    int i = 0;

    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|   index  |first name| last name| nick name|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while (i < 8 && i < this->i)
    {
        std::cout << "|    " << this->contatto[i].GetIndex() << "     |";
        ft_print_string(this->contatto[i].GetFirstName());
        std::cout << "|";
        ft_print_string(this->contatto[i].GetLastName());
        std::cout << "|";
        ft_print_string(this->contatto[i].GetNickname());
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::printCont(int i) const {
    if (i > this->i)
        return ;
    i--;
    std::cout << "Index: " << this->contatto[i].GetIndex() << std::endl;
    std::cout << "Firstname: " << this->contatto[i].GetFirstName() << std::endl;
    std::cout << "Lastname: " << this->contatto[i].GetLastName() << std::endl;
    std::cout << "Nickname: " << this->contatto[i].GetNickname() << std::endl;
    std::cout << "Phonenumber: " << this->contatto[i].GetPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contatto[i].GetDarkestSecret() << std::endl;
}

int PhoneBook::getI(void) const {
    return (this->i);
}
