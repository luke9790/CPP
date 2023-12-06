/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:55:14 by lmasetti          #+#    #+#             */
/*   Updated: 2023/12/06 11:56:50 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name(Name)
{
	try
	{
		if (Grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (Grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->Grade = Grade;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
    }
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : Name(copy.Name)
{
    this->Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign)
{
    this->Grade = assign.Grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return Name;
}

int Bureaucrat::getGrade() const
{
    return Grade;
}

void Bureaucrat::GetPromotion(int num)
{
    if (Grade - num < 1)
        throw Bureaucrat::GradeTooHighException();
    
    Grade -= num;
}

void Bureaucrat::GetDemotion(int num)
{
    if (Grade + num > 150)
        throw Bureaucrat::GradeTooLowException();
    
    Grade += num;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return out;
}

const char* Bureaucrat::GradeTooHighException::what( ) const throw ( )
{
	return ("Grade value is too high");
}

const char* Bureaucrat::GradeTooLowException::what( ) const throw( )
{
	return("Grade value is too low");
}