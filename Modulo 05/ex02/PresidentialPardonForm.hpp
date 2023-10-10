
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
	private:
	std::string	_target;
	PresidentialPardonForm(void);
	public:
	PresidentialPardonForm(const std::string&);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm(void);

	PresidentialPardonForm operator=(const PresidentialPardonForm&);

	void execute(Bureaucrat const & executor) const;
};

#endif

