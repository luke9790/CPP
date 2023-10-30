/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:40 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 10:48:56 by lmasetti         ###   ########.fr       */
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

		static std::vector<int>	vettore;
		static std::deque<int>	dique;

    public:

		static void Parsing(char** av);
		static void	FillContainers(int value);
		static void Exec(void);

		template<typename T>
		static void PrintContainer(const T& container, const std::string&);

		template<typename T>
		static void InsertionSort(T, T);

		template<typename T, typename TT>
		static void	MergeInsertionSort(T&, TT, TT);
};

#endif