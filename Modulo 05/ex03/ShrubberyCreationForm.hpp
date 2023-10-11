
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
	~ShrubberyCreationForm();

	ShrubberyCreationForm operator=(const ShrubberyCreationForm&);

	void execute(Bureaucrat const & executor) const;
	static AForm* gen(const std::string&);
};

#endif
