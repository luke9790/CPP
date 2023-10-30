/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 12:43:37 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: missing or invalid file." << std::endl;
        return 1;
    }
    std::string database = "./data.csv";
	std::string list = av[1];
	try
    {
		BitcoinExchange btc(database, list); // creiamo la nostra classe ma controlliamo anche gli input e popoliamo la mappa.
		btc.exchanger();
	}
	catch(const std::exception& e){ std::cerr << e.what() << std::endl; }
    
    return 0;
}
