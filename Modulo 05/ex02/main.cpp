#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
        Bureaucrat highGradeBureaucrat("Burocrate di alto grado", 1);
        Bureaucrat lowGradeBureaucrat("Burocrate di basso grado", 150);

        ShrubberyCreationForm shrubberyForm("Tizio, target di Form Shrub");
        RobotomyRequestForm robotomyForm("Caio, target di Form Robot");
        PresidentialPardonForm pardonForm("Sempronio, target di Form Pardon");
    try
    {
        std::cout << "\nTentiamo di eseguire un form non firmato\n" << std::endl;
        shrubberyForm.execute(highGradeBureaucrat);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n...\n" << std::endl;
	std::cout << "Firmiamo con beSigned un form non firmato (robotomy)\n" << std::endl;
	robotomyForm.beSigned(highGradeBureaucrat);

    try
    {
		std::cout << "\nProviamo a eseguire il form robotomy\n" << std::endl;
        robotomyForm.execute(highGradeBureaucrat);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n...\n" << std::endl;
    
    try
    {
        std::cout << "Proviamo a firmare alcuni form con burocrati diversi\n" << std::endl;
        highGradeBureaucrat.signForm(shrubberyForm);
		std::cout << "\n" << std::endl;
        lowGradeBureaucrat.signForm(robotomyForm);

		std::cout << "\n...\n" << std::endl;
        std::cout << "Proviamo a eseguire alcuni form con burocrati diversi\n" << std::endl;
        highGradeBureaucrat.executeForm(shrubberyForm); // Should execute the shrubbery creation form
        lowGradeBureaucrat.executeForm(robotomyForm);   // Should attempt robotomization
		std::cout << "\n...\n" << std::endl;
        // Attempt to execute a form with low-grade bureaucrat
        lowGradeBureaucrat.executeForm(pardonForm); // Should throw GradeTooLowException
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n...\n" << std::endl;
    
    try
    {
        // Sign and execute the presidential pardon form with a high-grade bureaucrat
        highGradeBureaucrat.signForm(pardonForm);
        highGradeBureaucrat.executeForm(pardonForm);
		std::cout << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
