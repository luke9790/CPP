#include "Form.hpp"

Form::Form(std::string Name, int GradeRequiredToSign, int GradeRequiredToExecute)
    : Name(Name), Signed(false), GradeRequiredToSign(GradeRequiredToSign), GradeRequiredToExecute(GradeRequiredToExecute)
{
    if (GradeRequiredToSign < 1 || GradeRequiredToExecute < 1)
        throw Form::GradeTooHighException();
    else if (GradeRequiredToSign > 150 || GradeRequiredToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form& copy)
    : Name(copy.Name), Signed(copy.Signed), GradeRequiredToSign(copy.GradeRequiredToSign), GradeRequiredToExecute(copy.GradeRequiredToExecute)
{
}

std::string Form::getName() const
{
    return Name;
}

bool Form::isSigned() const
{
    return Signed;
}

int Form::getGradeRequiredToSign() const
{
    return GradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
    return GradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= GradeRequiredToSign)
    {
        Signed = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade Required To Sign: " << form.getGradeRequiredToSign()
        << ", Grade Required To Execute: " << form.getGradeRequiredToExecute();
    return out;
}

const char* Form::GradeTooHighException::what() const throw ( )
{
    return ("Grade value is too high");
}

const char* Form::GradeTooLowException::what() const throw ( )
{
    return ("Grade value is too low");
}
