#pragma once
#include <vector>
#include "field.hpp"

struct Coordinates
{
    int x;
    int y;
};

class BoardI
{
public:
    virtual ~BoardI() = default;
    virtual Field at(const Coordinates&) const = 0;
    virtual void put(const Coordinates&, Field) = 0;
    virtual int sizeOfBoard() = 0; 
    virtual bool isFree(const Coordinates& ) const = 0;
};

using Columns = std::vector<Field>;
using Fields = std::vector<Columns>;

class Board : public BoardI
{
public:
    Board() = default;
    Field at(const Coordinates&) const override;
    void put(const Coordinates&, Field) override;
    int sizeOfBoard() override; 
    bool isFree(const Coordinates&) const override;

private:
    Fields fields = Fields(3, Columns(3, Field::EMPTY));
};
