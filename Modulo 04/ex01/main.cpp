#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
std::cout << "\nfine cane\n" << std::endl;
const Animal* i = new Cat();
std::cout << "\nfine gatto\n" << std::endl;
delete j;//should not create a leak
delete i;

std::cout << "\nfine due animali\n" << std::endl;
Animal zoo[10];
std::cout << "\nfine zoo\n" << std::endl;
int a = 0;
while(a < 5)
{
	zoo[a] = Dog();
	a++;
}
std::cout << "\nfine cani\n" << std::endl;
while(a < 10)
{
	zoo[a] = Cat();
	a++;
}
std::cout << "\nfine gatti\n" << std::endl;

// usando i puntatori
std::cout << "\ntest coi puntatori\n" << std::endl;

Animal* zoo2[10]; // Array di puntatori ad Animal
int a2 = 0;

while (a2 < 5)
{
	zoo2[a2] = new Dog(); // Usando new per creare nuovi oggetti Dog
	a2++;
}

std::cout << "\nfine cani\n" << std::endl;

while (a2 < 10)
{
    zoo2[a2] = new Cat(); // Usando new per creare nuovi oggetti Cat
    a2++;
}

std::cout << "\nfine gatti\n" << std::endl;

// Deallocazione dei puntatori
for (int i = 0; i < 10; i++)
{
	delete zoo2[i];
}

return 0;
}