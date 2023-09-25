#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string Name;
	int	Grade;

public:
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& assign);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void GetPromotion();
	void GetDemotion();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Grade is too high, daaa");
		}
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw() {
			return ("Grade is too low, daaa");
		}		
	};
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif