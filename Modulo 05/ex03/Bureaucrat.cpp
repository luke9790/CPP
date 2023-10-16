
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : Name(name) {
	try {
		if (grade < 1)
			throw(Bureaucrat::GradeTooHighException( ));
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException( ));
		Grade = grade;
	} catch (const std::exception& e) {
		Grade = 150;
		std::cout << e.what( ) << "so: ";
		std::cout << Name << " is set by default to " << Grade << std::endl;
		return;
	}
}

Bureaucrat::~Bureaucrat(void) { };

Bureaucrat::Bureaucrat(const Bureaucrat& raw) : Name(raw.Name), Grade(raw.Grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&raw) {
	if (this != &raw) {
		Grade = raw.getGrade( );
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& raw) {
	os << raw.getName( ) << ", bureaucrat grade " << raw.getGrade( );
	return (os);
}

const std::string Bureaucrat::getName(void) const {
    return (Name);
}

int Bureaucrat::getGrade (void) const {
	return (Grade);
}

void Bureaucrat::getPromotion(int val) {
	try {
		if (Grade - val < 1)
			throw (Bureaucrat::GradeTooHighException( ));
		else
			Grade -= val;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what( ) << std::endl; 
	}
}

void Bureaucrat::getDemotion(int val) {
	try {
		if (Grade + val > 150)
			throw (Bureaucrat::GradeTooLowException( ));
		else
			Grade += val;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what( ) << std::endl; 
	}
}

const char* Bureaucrat::GradeTooHighException::what( ) const throw ( ) {
	return ("Grade value is too high");
}

const char* Bureaucrat::GradeTooLowException::what( ) const throw( ) {
	return("Grade value is too low");
}

void Bureaucrat::signForm(AForm& raw) {
	try {
    	raw.beSigned(*this);
        std::cout << *this << " signed " << raw.getName() << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << Name << " could not sign " << raw.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &from) {
	try {
		from.execute(*this);
		std::cout << Name << " executed " << from.getName( ) << std::endl;
	} catch (std::exception& e) {
		std::cout << Name << " tried to execute " << from.getName( ) << " but " << e.what( ) << std::endl;
	}
}