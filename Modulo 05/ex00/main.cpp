/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:55:18 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/23 14:05:05 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main()
{
    
    Bureaucrat Supremo("Number one", 1);
    Bureaucrat Merda("Number 150", 160);
	std::cout << Supremo << std::endl;
	std::cout << Merda << std::endl;
	try
    {
        Bureaucrat okay("Cento", 100);
        std::cout << okay << std::endl;

		std::cout << "\nPromozione di 90 livelli\n" << std::endl;
        okay.GetPromotion(90);
        std::cout << okay << std::endl;
		std::cout << "\nDeclassamento di 90 livelli\n" << std::endl;
        okay.GetDemotion(90);
        std::cout << okay << std::endl;
		std::cout << "\nPromozione di 150 livelli (errore)\n" << std::endl;
        okay.GetPromotion(150);
        std::cout << okay << std::endl;
	}
	catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "\n...\n" << std::endl;
	try
    {
		std::cout << "Declassamento di 15 livelli (errore)\n" << std::endl;
        Merda.GetDemotion(15);
        std::cout << Merda << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "\n...\n" << std::endl;
	try
    {
		std::cout << "Declassamento di 15 livelli\n" << std::endl;
        Supremo.GetDemotion(15);
        std::cout << Supremo << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


