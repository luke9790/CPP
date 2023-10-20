/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:03:28 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/20 11:04:13 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : size(N)
{
    numbers.reserve(N);
}

void Span::addNumber(int number)
{
    if (numbers.size() < size)
	{
        numbers.push_back(number);
    }
	else
	{
        throw std::runtime_error("Span is full. Cannot add more numbers.");
    }
}

void Span::addNumbers(const std::vector<int>& newNumbers)
{
    if (numbers.size() + newNumbers.size() <= size)
	{
        numbers.insert(numbers.end(), newNumbers.begin(), newNumbers.end());
    } else {
        throw std::runtime_error("Span is full. Cannot add more numbers.");
    }
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
	{
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::sort(numbers.begin(), numbers.end());
    int minSpan = numbers[1] - numbers[0];
    for (size_t i = 2; i < numbers.size(); ++i)
	{
        int currentSpan = numbers[i] - numbers[i - 1];
        if (currentSpan < minSpan)
		{
            minSpan = currentSpan;
        }
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
	{
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::sort(numbers.begin(), numbers.end());
    int maxSpan = numbers[numbers.size() - 1] - numbers[0];
    return maxSpan;
}
