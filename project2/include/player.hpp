#pragma once
#include "field.hpp"



class Player
{
    private:

        Field symbol_; 

    
    public:
        Player(Field symbol):symbol_(symbol){};

        Field getSymbol() const; 

        bool makeMove() const;

};
