#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade)
{
	this->Name = Name;
	if(Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->Grade = Grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	this->Name = copy.Name;
	this->Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign)
{
	this->Name = assign.Name;
	this->Grade = assign.Grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
    return Name;
}

int Bureaucrat::getGrade() const
{
    return Grade;
}

void Bureaucrat::GetPromotion()
{
	if(Grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else if(Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->Grade--;
}

void Bureaucrat::GetDemotion()
{
	if(Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(Grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->Grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}