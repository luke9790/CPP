#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:

	public:
		Intern();
    	~Intern();
    	AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif