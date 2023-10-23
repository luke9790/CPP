/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:55:08 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/23 10:55:09 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string Name;
    int Grade;

public:
    Bureaucrat(std::string Name, int Grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& assign);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void GetPromotion(int num);
    void GetDemotion(int num);

    class GradeTooHighException : public std::exception
	{
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
	{
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
