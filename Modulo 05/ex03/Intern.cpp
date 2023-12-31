#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}


AForm* Intern::makeForm(const std::string& name, const std::string& target) 
{
    std::string list_request[] = {"shruberry request", "robotomy request", "presidential request"};
    std::string list[] = {"shruberry", "robotomy", "presidential"};
    std::string list_msg[] = {"Intern creates shrubbery form", "Intern creates robotomy form", "Intern creates presidential form", "Form request not found"};		
	// array di puntotori a funzione, richiede una stringa e torna un puntatore a Aform. il metodo gen serve a generare i metodi e cio' che richiedono
    AForm* (*fun[])(const std::string& target) = {&ShrubberyCreationForm::gen, &RobotomyRequestForm::gen, &PresidentialPardonForm::gen};

    for (int i = 0; i < 3; i++)
    {
        if (!list_request[i].compare(name) || !list[i].compare(name)) // controlliamo se la stringa name corrisponde a una delle liste nostre.
        {
            std::cout << list_msg[i] << std::endl;
            return fun[i](target);
        }
    }
    std::cout << list_msg[3] << std::endl;
    return NULL;  
}