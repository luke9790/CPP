#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "AForm.hpp"
# include "fstream"
# include "cstdlib"
class AForm;

class Bureaucrat {
	private:
		const std::string	Name;
		int					Grade;

		Bureaucrat(void);
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat(void);
		

		const std::string getName(void) const;
		int getGrade(void) const;

		void getPromotion(int);
		void getDemotion(int);

		class GradeTooHighException : public std::exception {
			public:
				const char* what( ) const throw ( );
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what( ) const throw( );
		};

		void signForm(AForm&);
		void executeForm(AForm const &);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif 