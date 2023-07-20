#include <iostream>
#include <string>

int main()
{
    std::string ciao = "HI THIS IS BRAIN";
    std::string *stringPTR = &ciao;
    std::string& stringREF = ciao;

    std::cout << "The memory address of the string variable = " << &ciao << std::endl ;
    std::cout << "The memory address held by stringPTR      = " << stringPTR << std::endl ;
    std::cout << "The memory address held by stringREF      = " << &stringREF << std::endl ;

    std::cout << "The value of the string variable  = " << ciao << std::endl ;
    std::cout << "The value pointed to by stringPTR = " << *stringPTR << std::endl ;
    std::cout << "The value pointed to by stringREF = " << stringREF << std::endl ;
}