#include "PhoneBook.hpp"

int ft_correctindex(std::string s)
{
    int i = 0;

    if (s[0] == '\0')
        return (0);
    if (s[i] >= '1' && s[i] <= '8' && s[1] == '\0')
        return (s[i] - 48);
    std::cout << "Please enter a valid index (a number between 1 and 8)" << std::endl;
    return (-1);
}

int main(void)
{
    PhoneBook rubrica;
    std::string input;

    std::cout << "Please enter one of these commands:\n - ADD (add contact)\n - SEARCH (search contact in phonebook)\n - EXIT " << std::endl;
    std::cout << "Your Phonebook > ";
    while (std::getline(std::cin, input) && input.compare("EXIT") != 0 && input.compare("exit") != 0)
    {
        if (input.compare("ADD") == 0 || input.compare("add") == 0)
        {
            rubrica.addContact();
            std::cout << "Contact added!" << std::endl;
        } 
        else if(input.compare("SEARCH") == 0 || input.compare("search") == 0)
        {
            rubrica.search();
            std::cout << std::endl;
            std::cout << "Select a contact index to get information or press 'ENTER' to skip: ";
            std::getline(std::cin, input);
            while (ft_correctindex(input) == -1)
            {
                std::cout << "Select: ";
                std::getline(std::cin, input);
            }
            if (ft_correctindex(input))
                rubrica.printCont(ft_correctindex(input));
        }
        std::cout << "Your Phonebook > ";
    }
    return (0);
}