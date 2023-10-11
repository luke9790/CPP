#include "AForm.hpp"

AForm::AForm(const std::string& name, int sing, int execute) : Name(name), isSigned(false), gradeToSign(sing), gradeToExec(execute)
{

    if (gradeToSign < 0)
        throw(GradeTooHighException( ));
    if (gradeToSign > 150)
        throw(GradeTooLowException( ));

    if (gradeToExec < 0)
        throw(GradeTooHighException( ));
    if (gradeToExec > 150)
        throw(GradeTooLowException( ));

}

AForm::AForm(const std::string& name, int sing) : Name(name), isSigned(false), gradeToSign(sing), gradeToExec(150)
{
    if (gradeToSign < 0)
        throw(GradeTooHighException( ));
    if (gradeToSign > 150)
        throw(GradeTooLowException( ));
}

AForm::AForm(const AForm &raw) : Name(raw.Name), isSigned(raw.isSigned), gradeToSign(raw.gradeToSign), gradeToExec(raw.gradeToExec)
{

}

AForm::~AForm() { }

AForm& AForm::operator=(const AForm& raw)
{
    if (this != &raw)
    {
        isSigned = raw.isSigned;
    }
    return (*this);
}

const std::string AForm::getName(void) const
{
    return (Name);
}

bool AForm::getSigned(void) const
{
    return (isSigned);
}
int AForm::getGradeToSign(void) const 
{
    return (gradeToSign);
}
int AForm::getGradeToExecute(void) const 
{
    return (gradeToExec);
}

const char* AForm::GradeTooHighException::what() const throw ( ) 
{
    return ("Grade value is too high");
}

const char* AForm::GradeTooLowException::what() const throw ( ) 
{
    return ("Grade value is too low");
}

void AForm::beSigned(const Bureaucrat& raw) 
{
    try 
    {
        if (raw.getGrade( ) <= gradeToSign) {
            isSigned = true;
            std::cout << raw.getName( ) << " has successfully signed the form called " << this->Name << std::endl;
        }
        else
            throw(GradeTooLowException( ));
    }
    catch(const std::exception& e) {
        std::cout << raw.getName( ) << " is unable to sign the " << this->Name << " form\n";
        std::cout << e.what( ) << std::endl;
    }
    std::cout << "[grade to sign:" << gradeToSign << "  bureaucrat grade:" << raw.getGrade( ) << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& raw) 
{
    os << "name: " << raw.getName( ) << std::endl;
    os << "signed: ";
    raw.getSigned( ) != 0 ? os << "yes" : os << "no";
    os << std::endl;
    os << "grade to sign: " << raw.getGradeToSign( ) << std::endl;
    os << "grade to execute: " << raw.getGradeToExecute( ) << std::endl;
    return (os);
}

const char* AForm::GradeTooLowSign::what( ) const throw( ) {
	return ("grade is too low to Sign this");
}

const char* AForm::GradeTooLowExecute::what( ) const throw( ) {
    return ("grade is too low to Execute this");

}
const char* AForm::FormNotSign::what( ) const throw( ) {
	return ("The form is not signed!");
}