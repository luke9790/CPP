#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("RobotomyRequestForm") 
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm(target, 72, 45), _target(target) 
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& raw) : AForm(raw._target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm( ) {}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm& raw) {
	(void)raw;
	std::cout << "[RobotomyRequestForm] assignament operator call" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->AForm::getIsSigned( )) {
        throw(FormNotSign( ));
        return ;
    }
    if (this->AForm::getGradeToSign( ) < executor.getGrade( )) {
        throw(GradeTooLowSign( ));
        return ;
    }
    if (this->AForm::getGradeToExecute( ) < executor.getGrade( )) {
        throw(GradeTooLowExecute( ));
        return ;
    }
    if (rand( ) % 2)
	    std::cout << _target << " has been robotomized" << std::endl;
    else
    	    std::cout << _target << " hasn't been robotomized" << std::endl;
}

AForm* RobotomyRequestForm::gen(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}