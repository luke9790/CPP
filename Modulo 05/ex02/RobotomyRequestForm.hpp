
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
	private:
	std::string	_target;

	public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& raw);
	~RobotomyRequestForm(void);

	RobotomyRequestForm operator=(const RobotomyRequestForm&);

	void execute(Bureaucrat const & executor) const;
};

#endif

