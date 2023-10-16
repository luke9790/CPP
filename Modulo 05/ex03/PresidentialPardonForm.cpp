
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("PresidentialPardonForm") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& raw) : AForm(raw._target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm( ) {}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm& raw) {
	(void)raw;
	std::cout << "[PresidentialPardonForm] assignament operator call" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
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
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::gen(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}