/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/26 16:17:07 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top of MutantStack: " << mstack.top() << std::endl;


    std::cout << "Size of MutantStack: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
	std::cout << "Added 4 more elements\n" << std::endl;
    std::cout << "Testing MutantStack with custom iterator:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\nTesting with std::list:" << std::endl;
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(17);
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::list<int>::iterator lit = myList.begin();
    std::list<int>::iterator lite = myList.end();

    std::cout << "Testing custom iterator for std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n\nTesting typedefs for MutantStack:" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
	std::cout << "Testing const_iterator for MutantStack:" << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
	std::cout << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "Testing reverse_iterator for MutantStack:" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
	std::cout << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	std::cout << "Testing const_reverse_iterator for MutantStack:" << std::endl;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }
    
    return 0;
}
