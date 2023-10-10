#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string Name;
    bool Signed;
    const int GradeRequiredToSign;
    const int GradeRequiredToExecute;

public:
    Form(std::string Name, int GradeRequiredToSign, int GradeRequiredToExecute);
    Form(const Form& copy);
    Form& operator=(const Form& assign);
    ~Form();

    std::string getName() const;
    bool isSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif