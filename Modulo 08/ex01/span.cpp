/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:03:28 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/26 12:41:58 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int N) : size(N)
{
	try
	{
        vettore.reserve(N);
	}
	catch (const std::bad_alloc& e) 
	{
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

Span::Span(const Span& other)
{
    this->vettore = other.vettore;
    this->size = other.size;
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
	{
        return *this;
    }
    this->vettore = other.vettore;
    this->size = other.size;

    return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if (vettore.size() < size)
	{
        vettore.push_back(number);
    }
	else
	{
        throw std::runtime_error("Span is full. Cannot add more numbers.");
    }
}

/*
insert chiede Position, First, Last. Usiamo end per dire di aggiungere roba
prima della fine del vettore, poi diciamo start e stop degli elementi da inserire.
*/

void Span::addNumbers(const std::vector<int>& newNumbers)
{
    if (vettore.size() + newNumbers.size() <= size)
	{
        vettore.insert(vettore.end(), newNumbers.begin(), newNumbers.end());
    } else {
        throw std::runtime_error("Span is full. Cannot add more numbers.");
    }
}

/*
Sort mette in ordine dal piu piccolo al piu grande i numeri(chiede start e end)
*/

int Span::shortestSpan()
{
    if (vettore.size() < 2)
	{
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::sort(vettore.begin(), vettore.end());
    int minSpan = vettore[1] - vettore[0];
    for (size_t i = 2; i < vettore.size(); ++i)
	{
        int currentSpan = vettore[i] - vettore[i - 1];
        if (currentSpan < minSpan)
		{
            minSpan = currentSpan;
        }
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (vettore.size() < 2)
	{
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::sort(vettore.begin(), vettore.end());
    int maxSpan = vettore[vettore.size() - 1] - vettore[0];
    return maxSpan;
}
