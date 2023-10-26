/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:44 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/26 12:11:47 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    std::vector<int> vettore;
    unsigned int size;

public:
    Span(unsigned int N);
	Span(const Span& other);
    Span& operator=(const Span& other);
	~Span();

    void addNumber(int number);
    void addNumbers(const std::vector<int>& newNumbers);
    int shortestSpan();
    int longestSpan();
};

#endif