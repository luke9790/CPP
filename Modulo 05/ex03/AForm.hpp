
#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private:
		const std::string	Name;
		bool				IsSigned;
		const int			gradeToSign;
		const int			gradeToExec;
		
		AForm( );
	public:
		AForm(const std::string&, int, int);
		AForm(const std::string&, int);
		AForm(const AForm&);
		virtual ~AForm();

		AForm& operator=(const AForm&);

		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw ( );
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw ( );
		};

		class GradeTooLowSign : public std::exception
		{
			public:
				const char* what( ) const throw( );
		};
		class GradeTooLowExecute : public std::exception
		{
			public:
				const char* what( ) const throw( );
		};
		class FormNotSign : public std::exception
		{
			public:
				const char* what( ) const throw( );
		};

		void beSigned(const Bureaucrat&) ;
		virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif