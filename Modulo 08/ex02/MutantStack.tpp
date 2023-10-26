/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:13 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/26 15:28:46 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
	/*
	c is a member of the std::stack class that is being inherited 
	in your MutantStack class. The c member is the container 
	(usually a std::deque) that holds the elements of the stack.
	*/

	this->c.clear(); // Clear the current contents to start with an empty stack.
  	for (typename std::stack<T>::container_type::const_iterator it = src.c.begin(); it != src.c.end(); ++it)
	{
   		const T& value = *it;
    	this->c.push_back(value); // Push a copy of each value from 'src' to the new stack.
	}
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
    if (this == &src) {
        return *this;
    }
    std::stack<T>::operator=(src);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return this->c.cend();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return this->c.crbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return this->c.crend();
}

