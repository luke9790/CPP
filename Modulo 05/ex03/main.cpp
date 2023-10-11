#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    Bureaucrat burocrate("burocrate", 70);
    Intern intern;

    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Form Garden");
    AForm* robotomyForm = intern.makeForm("robotomy request", "Form Robot");

    if (shrubberyForm) {
        std::cout << std::endl;
        burocrate.executeForm(*shrubberyForm);
        std::cout << std::endl;
        burocrate.signForm(*shrubberyForm);
        std::cout << std::endl;
        burocrate.executeForm(*shrubberyForm);
        std::cout << std::endl;
        delete shrubberyForm;
    }

    if (robotomyForm) {
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


