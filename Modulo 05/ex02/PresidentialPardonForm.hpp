
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
	private:
	std::string	_target;

	public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& raw);
	~PresidentialPardonForm(void);

	PresidentialPardonForm operator=(const PresidentialPardonForm&);

	void execute(Bureaucrat const & executor) const;
};

#endif

