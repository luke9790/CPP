#include "./Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name(Name)
{
    if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->Grade = Grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : Name(copy.Name)
{
    this->Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign)
{
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

void Bureaucrat::GetPromotion(int num)
{
    if (Grade - num < 1)
        throw Bureaucrat::GradeTooHighException();
    
    Grade -= num;
}

void Bureaucrat::GetDemotion(int num)
{
    if (Grade + num > 150)
        throw Bureaucrat::GradeTooLowException();
    
    Grade += num;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return out;
}

const char* Bureaucrat::GradeTooHighException::what( ) const throw ( )
{
	return ("Grade value is too high");
}

const char* Bureaucrat::GradeTooLowException::what( ) const throw( )
{
	return("Grade value is too low");
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << Name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << Name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}