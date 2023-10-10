#include "./Bureaucrat.hpp"

int main()
{
    
    Bureaucrat Supremo("Number one", 1);
    Bureaucrat Merda("Number 150", 150);

	try
    {
        Bureaucrat okay("cento", 100);
        std::cout << okay << std::endl;

        okay.GetPromotion(90);
        std::cout << okay << std::endl;

        okay.GetDemotion(90);
        std::cout << okay << std::endl;

        okay.GetPromotion(150);
        std::cout << okay << std::endl;
	}
	catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "\n...\n" << std::endl;
	try
    {
        Merda.GetDemotion(15);
        std::cout << Merda << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "\n...\n" << std::endl;
	try
    {
        Supremo.GetDemotion(15);
        std::cout << Supremo << std::endl;

        Bureaucrat copy = Bureaucrat(Supremo);
        std::cout << copy << std::endl;

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


