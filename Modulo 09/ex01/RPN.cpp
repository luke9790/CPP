/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:49:15 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 11:33:41 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>			RPN::stacche;

const std::string inputvalidi("1234567890/*-+ ");
const std::string cifre("1234567890");
const std::string operazioni("/*-+");

// se il carattere at posizione i non rientra negli input validi lancia l'errore.

void RPN::Parsing(char *av)
{
	std::string arg(av);
	for (size_t i = 0; i < arg.size( ); i++)
		if (inputvalidi.find(arg.at(i)) == std::string::npos)
			throw std::invalid_argument("Error.");
}

/*
Se abbiamo meno di due cifre nel nostro stacche hanno inserito un input sbagliato.
Ci salviamo i numeri su first e second, usiamo pop per cancellarli dallo stacche.
A sto punto gestiamo l'operazione(che e' passata come parametro) e, dopo aver 
fatto il calcolo, ripushiamo il numero ottenuto nello stack. Ripetiamo fino alla fine
dell'input.
TOP prende il primo elemento, POP cancella il primo elemento, PUSH inserisce in cima l'elemento.
Dopo il primo ciclo, la somma delle operazioni precedenti e' su second.
*/

void RPN::Operations(std::string& op)
{
	int	first;
	int second;

	if (stacche.size( ) < 2)
    	throw std::invalid_argument("Error: Not enough operands for operator!");
	first = stacche.top( );
	stacche.pop( );
	second = stacche.top( );
	stacche.pop( );

	if (op == "+")
		stacche.push(second + first);
	if (op == "-")
		stacche.push(second - first);
	if (op == "*")
		stacche.push(second * first);
	if (op == "/") {
		if (first == 0)
			throw std::invalid_argument("Error: Can't divide by 0!");
	stacche.push(second / first);
	}
}

/*
Ci salviamo l'input su su stringstream stream e creiamo una stringa dove
salvare ogni singolo elemento estratto dall input. Iniziamo a leggere l input
con getline, estreando ogni elemento separato da spazio su element.
Se element non rientra nelle cifre o nelle operazioni errore.
Se troviamo una cifra la pushiamo dopo averla convertita con atoi.
Se troviamo un operazione facciamo partire la funzione dedicata.
*/

void RPN::Fill(char *av)
{
    std::istringstream stream(av);
    std::string element;

    while (std::getline(stream, element, ' '))
    {
        if (element.empty())
            continue;

        if (cifre.find(element) == std::string::npos && operazioni.find(element) == std::string::npos)
        {
            throw std::invalid_argument("Error.");
        }

        if (cifre.find(element) != std::string::npos)
        {
            stacche.push(std::atoi(element.c_str()));
        }
        else if (operazioni.find(element) != std::string::npos)
        {
            RPN::Operations(element);
        }
    }
	// se la size e' 1 abbiamo fatto tutte le operazioni e stampiamo.
    if (stacche.size() == 1)
    {
        std::cout << stacche.top() << std::endl;
    }
    else
    {
        throw std::invalid_argument("Error.");
    }
}