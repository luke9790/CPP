#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

std::cout << "\nImplementazione classi derivate sbagliate\n" << " " << std::endl;

const Animal* meta2 = new Animal();
const Animal* j2 = new Dog();
const WrongAnimal* i2 = new WrongCat();
std::cout << j2->getType() << " " << std::endl;
std::cout << i2->getType() << " " << std::endl;
i2->makeSound(); //will NOT output the cat sound!
j2->makeSound();
meta2->makeSound();

delete meta2;
delete j2;
delete i2;


return 0;
}