#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 50);
        Bureaucrat alice("Alice", 75);

        std::cout << "Initial Bureaucrats:" << std::endl;
        std::cout << john << std::endl;
        std::cout << alice << std::endl;

        Form taxForm("Tax Form", 45, 30);
        Form contractForm("Contract Form", 60, 40);

        std::cout << "\nInitial Forms:" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << contractForm << std::endl;

        // Attempt to promote and demote bureaucrats
        try
        {
            john.GetPromotion(10);
            std::cout << "\nJohn promoted 10 levels:" << std::endl;
            std::cout << john << std::endl;

            alice.GetDemotion(20);
            std::cout << "\nAlice demoted 20 levels:" << std::endl;
            std::cout << alice << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nLet's try to sign the forms:" << std::endl;
        try
        {
            john.signForm(taxForm);
            alice.signForm(contractForm);
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}