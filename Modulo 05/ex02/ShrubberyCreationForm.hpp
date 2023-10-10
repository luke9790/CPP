
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
	std::string	_target;
	ShrubberyCreationForm(void);
	public:
	ShrubberyCreationForm(const std::string&);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm operator=(const ShrubberyCreationForm&);

	void execute(Bureaucrat const & executor) const;
};

#endif
