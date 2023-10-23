#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
    try
    {
        Bureaucrat marco("Marco", 50);
        Bureaucrat alice("Alice", 75);

        std::cout << "Initial Bureaucrats:" << std::endl;
        std::cout << marco << std::endl;
        std::cout << alice << std::endl;

        Form taxForm("Tax Form", 45, 30);
        Form contractForm("Contract Form", 60, 40);

        std::cout << "\nInitial Forms:" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << contractForm << std::endl;

        try
        {
            marco.GetPromotion(10);
            std::cout << "\nMarco promoted 10 levels:" << std::endl;
            std::cout << marco << std::endl;

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
            marco.signForm(taxForm);
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