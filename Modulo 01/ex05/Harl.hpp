/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:08:25 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/01 14:49:03 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>
#include <map>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();

	void complain(std::string level);
};

typedef void (Harl::*func)(void);
// tipo_di_ritorno (NomeClasse::*nome_puntatore)(argomenti);
// sintassi per la dichiarazione di un puntatore a funzione membro è la seguente:

#endif