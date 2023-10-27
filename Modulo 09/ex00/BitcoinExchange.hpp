/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:14:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:40 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, float> dataMap;
	std::string listPath;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string& database, const std::string& list);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

	void populateMap(const std::string& database);
	void exchanger() const;
};

#endif