/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:40 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/27 15:53:33 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "limits"
# include "iostream"
# include "cstdlib"
# include "iterator"
# include "algorithm"

# include "vector"
# include "deque"

extern const std::string cifre;

class PmergeMe
{
	private:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		static std::vector<int>	_vector;
		static std::deque<int>	_deque;

    public:

		static void ParsArgs(char**);
		static void	FillContainer(int);
		static void Time(void);

		template<typename T>
		static void PrintContainer(const T& container, const std::string&);

		template<typename T>
		static void InsertionSort(T, T);

		template<typename T, typename IT>
		static void	MergeInsertion(T&, IT, IT);
};

#endif