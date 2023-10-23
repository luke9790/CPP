
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm(target, 147, 137), _target(target)
{
	std::cout << "[ShrubberyCreationForm] constructor call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& raw) : AForm(raw._target, 147, 137)
{
	std::cout << "[ShrubberyCreationForm] copy constructor call" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( )
{
	std::cout << "[ShrubberyCreationForm] destructor call" << std::endl;
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(const ShrubberyCreationForm& raw)
{
	std::cout << "[ShrubberyCreationForm] assignament operator call" << std::endl;
    _target = raw._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->AForm::getIsSigned( )) {
        throw(FormNotSign( ));
        return ;
    }
    if (this->AForm::getGradeToSign( ) < executor.getGrade( ))
	{
        throw(GradeTooLowSign( ));
        return ;
    }
    if (this->AForm::getGradeToExecute( ) < executor.getGrade( ))
	{
        throw(GradeTooLowExecute( ));
        return ;
    }

    std::string file_name(_target + "_shrubbery");
    std::ofstream out_file(file_name.c_str( ), std::ios::trunc);

    if (!out_file.good( ))
	{
		std::cerr << "unable to open file" << std::endl;
		return ;
	}

    out_file <<"          &&& &&  & &&          "<< std::endl;
    out_file <<"      && &\\/&\\|& ()|/ @, &&   "<< std::endl;
    out_file <<"      &\\/(/&/&||/& /_/)_&/_&   "<< std::endl;
    out_file <<"   &() &\\/&|()|/&\\/ '%\" & () "<< std::endl;
    out_file <<"  &_\\_&&_\\ |& |&&/&__%_/_& && "<< std::endl;
    out_file <<"&&   && & &| &| /& & % ()& /&&  "<< std::endl;
    out_file <<" ()&_---()&\\&\\|&&-&&--%---()~ "<< std::endl;
    out_file <<"        &&  \\|||               "<< std::endl;
    out_file <<"             |||                "<< std::endl;
    out_file <<"             |||                "<< std::endl;
    out_file <<"             |||                "<< std::endl;
    out_file <<"       , -=-~  .-^- _         "<< std::endl;
    out_file <<"              `               "<< std::endl;

	out_file.close( );

    return ;
}