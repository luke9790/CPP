/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:44 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/20 11:04:31 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
    std::vector<int> numbers;
    unsigned int size;

public:
    Span(unsigned int N);
    void addNumber(int number);
    void addNumbers(const std::vector<int>& newNumbers);
    int shortestSpan();
    int longestSpan();
};

#endif