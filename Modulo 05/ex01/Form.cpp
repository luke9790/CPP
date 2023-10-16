#include "Form.hpp"

Form::Form(std::string Name, int GradeToSign, int GradeToExec)
    : Name(Name), isSigned(false), GradeToSign(GradeToSign), GradeToExec(GradeToExec)
{
    if (GradeToSign < 1 || GradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (GradeToSign > 150 || GradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form& copy)
    : Name(copy.Name), isSigned(copy.isSigned), GradeToSign(copy.GradeToSign), GradeToExec(copy.GradeToExec)
{
}

std::string Form::getName() const
{
    return Name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return GradeToSign;
}

int Form::getGradeToExec() const
{
    return GradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= GradeToSign)
    {
        isSigned = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade Required To Sign: " << form.getGradeToSign()
        << ", Grade Required To Execute: " << form.getGradeToExec();
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
