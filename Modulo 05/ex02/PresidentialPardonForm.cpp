
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm(target, 25, 5), _target(target) {
	std::cout << "[PresidentialPardonForm] constructor call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& raw) : AForm(raw._target, 25, 5) {
	std::cout << "[PresidentialPardonForm] copy constructor call" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( ) {
	std::cout << "[PresidentialPardonForm] destructor call" << std::endl;
}

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