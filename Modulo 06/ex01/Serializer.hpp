/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:53 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 11:36:54 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include "Data.hpp"
#include <stdint.h>
#include "iostream"

struct Data;

class Serializer
{
    private:

        Serializer(void);
        ~Serializer(void);
        Serializer(Serializer&);
        Serializer& operator=(const Serializer&);

    public:
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif