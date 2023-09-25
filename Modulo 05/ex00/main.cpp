#include "./Bureaucrat.hpp"

int main()
{
	Bureaucrat loli("gino", 10);
	Bureaucrat popi = loli;
	Bureaucrat koki;
	Bureaucrat hohi(popi);

	try
	{
		Bureaucrat toti("alpi", 200);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	loli.upGrade(2);
	hohi.downGrade(5);
	std::cout << loli << std::endl;
	std::cout << popi << std::endl;
	std::cout << koki << std::endl;
	std::cout << hohi << std::endl;

	try
	{
		loli.downGrade(100);
		std::cout << loli << std::endl;
		popi.upGrade(1);
		std::cout << popi << std::endl;
		koki.downGrade(0);
		std::cout << koki << std::endl;
		hohi.upGrade(5);
		std::cout << hohi << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}