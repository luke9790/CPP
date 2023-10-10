#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
    const std::string Name;
    int Grade;

public:
    Bureaucrat(std::string Name, int Grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& assign);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void GetPromotion(int num);
    void GetDemotion(int num);
    void signForm(Form& form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
