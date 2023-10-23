
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
	std::string	_target;
	
	public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& raw);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm operator=(const ShrubberyCreationForm&);

	void execute(Bureaucrat const & executor) const;
};

#endif
