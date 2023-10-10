#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
        Bureaucrat highGradeBureaucrat("Burocrate di alto grado", 1);
        Bureaucrat lowGradeBureaucrat("Burocrate di basso grado", 150);

        ShrubberyCreationForm shrubberyForm("Form Shrub");
        RobotomyRequestForm robotomyForm("Form Robot");
        PresidentialPardonForm pardonForm("Form Pardon");
    try
    {
        // Attempt to execute unsigned forms
        shrubberyForm.execute(highGradeBureaucrat); // Should throw FormNotSignedException
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n...\n" << std::endl;

    try
    {
        robotomyForm.execute(lowGradeBureaucrat);   // Should throw FormNotSignedException
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n...\n" << std::endl;
    
    try
    {
        // Sign the forms
        highGradeBureaucrat.signForm(shrubberyForm);
        lowGradeBureaucrat.signForm(robotomyForm);

        // Execute the signed forms
        highGradeBureaucrat.executeForm(shrubberyForm); // Should execute the shrubbery creation form
        lowGradeBureaucrat.executeForm(robotomyForm);   // Should attempt robotomization

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

        // Promote and demote bureaucrats
        highGradeBureaucrat.getDemotion(10);
        lowGradeBureaucrat.getPromotion(10);

        // Attempt to execute the presidential pardon form again after promotions/demotions
        lowGradeBureaucrat.executeForm(pardonForm); // Should now succeed

        // Print bureaucrat details
        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
