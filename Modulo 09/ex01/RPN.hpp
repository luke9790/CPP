/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:49:22 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 11:08:08 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "stdexcept"
# include "stack"
# include "sstream"
# include "iostream"
# include "cstdlib"

extern const std::string cifre;
extern const std::string operazioni;
extern const std::string inputvalidi;

class RPN
{
	private:
		static std::stack<int>			stacche;
		RPN(void);
		~RPN(void);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
	public:
		static void	Parsing( char *av);
		static void Fill(char *av);
		static void Operations(std::string&);
};

#endif