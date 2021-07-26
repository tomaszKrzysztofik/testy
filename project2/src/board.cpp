#include "board.hpp"
#include "field.hpp"

Field Board::at(const Coordinates& coords) const
{
    return fields[coords.x][coords.y];
}

void Board::put(const Coordinates& coords, Field symbol)
{
    if(fields[coords.x][coords.y] == Field::EMPTY)
        fields[coords.x][coords.y] = symbol;
}



int Board::sizeOfBoard()
{
    return fields.size();
}

bool Board::isFree(const Coordinates& coords) const
{
    return fields[coords.x][coords.y] == Field::EMPTY;
}

