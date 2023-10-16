#include "./Bureaucrat.hpp"

int main()
{
    
    Bureaucrat Supremo("Number one", 1);
    Bureaucrat Merda("Number 150", 150);
	std::cout << Supremo << std::endl;
	std::cout << Merda << std::endl;
	try
    {
        Bureaucrat okay("Cento", 100);
        std::cout << okay << std::endl;

		std::cout << "\nPromozione di 90 livelli\n" << std::endl;
        okay.GetPromotion(90);
        std::cout << okay << std::endl;
		std::cout << "\nDeclassamento di 90 livelli\n" << std::endl;
        okay.GetDemotion(90);
        std::cout << okay << std::endl;
		std::cout << "\nPromozione di 150 livelli (errore)\n" << std::endl;
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
		std::cout << "Declassamento di 15 livelli (errore)\n" << std::endl;
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
		std::cout << "Declassamento di 15 livelli\n" << std::endl;
        Supremo.GetDemotion(15);
        std::cout << Supremo << std::endl;
		std::cout << "\nNuovo burocrate fatto con copy assign\n" << std::endl;
        Bureaucrat copy = Bureaucrat(Supremo);
        std::cout << copy << std::endl;

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


