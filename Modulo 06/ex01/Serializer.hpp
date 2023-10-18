#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

# include "Data.hpp"
# include "iostream"

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