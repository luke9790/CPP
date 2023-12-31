/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:14:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 12:42:50 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : dataMap(src.dataMap), listPath(src.listPath){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src){
		this->dataMap = src.dataMap;
		this->listPath = src.listPath; 
	}
	return *this;
}

bool isValidFile(const std::string& path)
{
	std::ifstream file(path.c_str());
	if (!file)
		return false;
	file.close();
	return true;
}

/*
Controlliamo nel costruttore se i file sono validi.
*/

BitcoinExchange::BitcoinExchange(const std::string& database, const std::string& list)
{
	if (!isValidFile(database))
		throw std::runtime_error("Error: could not open database file");
	if (!isValidFile(list))
		throw std::runtime_error("Error: could not open list file");
	this->listPath = list;
	populateMap(database);
}

/*
Leggiamo il nostro database linea per linea. Salviamo la linea su iss e la ridividiamo
in base alla virgola. Ora possiamo salvare separatamente il valore e la data nella nostra mappa.
Chiudiamo alla fine il database. */

void BitcoinExchange::populateMap(const std::string& database)
{
	std::string line, date;
	std::ifstream db(database.c_str());
	float value;
	while (std::getline(db, line)){
		std::istringstream iss(line);
        std::getline(iss, date, ',');
        iss >> value;
        dataMap[date] = value;
	}
	db.close();
}

// la funzione compare fa il lavoro sporco per noi. Fintanto la prima data e' precedente
// ritorna vero.

bool dateFinder(const std::string& date1, const std::string& date2)
{
	return date1.compare(date2) <= 0;
}

// controlliamo se la data e' valida con alcuni parametri (non esaustiva)

bool isDateValid(const std::string& date)
{
    std::istringstream iss(date);
    int year, month, day;
    char delimiter;

    if (iss >> year >> delimiter >> month >> delimiter >> day)
            if (year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
                return true;
    return false;
}

void printer(const std::string& targetDate, const float& dataValue, const float& listValue)
{
	if (!isDateValid(targetDate))
		std::cerr << "Error: bad input => " << targetDate << std::endl;
	else if (listValue < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (listValue > 1000)
		std::cerr << "Error: too large number." << std::endl;
	else
		std::cout << targetDate << " => " << listValue << " = " << std::fixed << std::setprecision(2) << listValue * dataValue << std::endl;
}

/*
Apriamo su lst il file salvato su listPath. Con getline leggiamo tutto il file,
saltando il primo rigo(che riposta la struttura e non i dati). Leggiamo dunque un rigo alla volta.
Usiamo iss per salvare la riga e usiamo ancora getline per distinguere il prima e il dopo la pipe.
TargetDate prende la prima parte, Listvalue la seconda. Entriamo nel for loop, dove iteriamo la
mappa al contrario (reverse iterator, rit) e compariamo la data dove siamo con quella del target.
Assegniamo quindi la data piu vicina(o la stessa) del database per calcolare il valore.
Passiamo infine a printer che stampa il necessario e chiudiamo la lista.
*/

void BitcoinExchange::exchanger() const
{
	std::string line, targetDate;
	float dataValue, listValue;

	std::ifstream lst(listPath.c_str());
	std::getline(lst, line);
	while (std::getline(lst, line))
	{
		std::istringstream iss(line);
		std::getline(iss, targetDate, '|');
		iss >> listValue;
		for (std::map<std::string, float>::const_reverse_iterator rit = dataMap.rbegin(); rit != dataMap.rend(); ++rit)
		{
			if (dateFinder(rit->first, targetDate)) // se e' falsa siamo andati troppo indietro e riporta la data successiva.
			{
				dataValue = rit->second;
				break;
			}
		}
		printer(targetDate, dataValue, listValue);
	}
	lst.close();
}