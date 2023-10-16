#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) 
{
    Bureaucrat burocrate("Burocrate", 70);
    Intern intern;


	std::cout << "Proviamo a creare due form con lo stagista, la prima form non esiste\n" << std::endl;
    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Form Garden");
    AForm* robotomyForm = intern.makeForm("robotomy request", "Form Robot");

    if (shrubberyForm)
	{
        std::cout << std::endl;
        burocrate.executeForm(*shrubberyForm);
        std::cout << "\nFacciamo firmare la form" << std::endl;
        burocrate.signForm(*shrubberyForm);
        std::cout << std::endl;
        burocrate.executeForm(*shrubberyForm);
        std::cout << std::endl;
        delete shrubberyForm;
    }

    if (robotomyForm)
	{
        std::cout << std::endl;
        burocrate.executeForm(*robotomyForm);
        std::cout << std::endl;
        burocrate.signForm(*robotomyForm);
        std::cout << std::endl;
        burocrate.executeForm(*robotomyForm);
        std::cout << std::endl;
        delete robotomyForm;
    }

    return 0;
}


