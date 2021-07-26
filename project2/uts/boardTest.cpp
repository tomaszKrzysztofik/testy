#include "board.hpp"
#include "field.hpp"
#include "gtest/gtest.h"

std::ostream& operator<<(std::ostream& str, Field in)
{
    switch (in)
    {
        case Field::EMPTY:
            return str << "EMPTY";
        case Field::X:
            return str << "X";
        case Field::O:
            return str << "O";
    }
    return str;
}

class BoardTest : public ::testing::Test
{
};

TEST_F(BoardTest, whenFreshlyCreatedAll9FieldsAreEmpty)
{
    Board sut;

    EXPECT_EQ(sut.at({0, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({0, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({0, 2}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 2}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 2}), Field::EMPTY);
}

TEST_F(BoardTest, whenAskedIfField2and2IsEmptyReturnTrue)
{
    Board sut;
    EXPECT_TRUE(sut.isFree({2,2}));
}

TEST_F(BoardTest, whenXPutOnEmptyCoodinate1and2ThenXIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({1, 2}, Field::X);

    EXPECT_EQ(sut.at({1, 2}), Field::X);
}

TEST_F(BoardTest, when0PutOnEmptyCoodinate2and2ThenOIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({2, 2}, Field::O);

    EXPECT_EQ(sut.at({2, 2}), Field::O);
}

TEST_F(BoardTest, whenXPutOnEmptyCoodinate0and0ThenXIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({0, 0}, Field::X);

    EXPECT_EQ(sut.at({0, 0}), Field::X);
}

TEST_F(BoardTest, whenOPutOnXCoodinate0and0ThenXIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({0, 0}, Field::X);
    sut.put({0, 0}, Field::O);

    EXPECT_EQ(sut.at({0, 0}), Field::X);
}
// Jeżeli test nie wywala nowego bledu to nie jest potrzebny
// TEST_F(BoardTest, whenXPutOnOCoodinate0and0ThenOIsReturnedForThisCoordinate)
// {
//     Board sut;

//     sut.put({0, 0}, Field::O);
//     sut.put({0, 0}, Field::X);

//     EXPECT_EQ(sut.at({0, 0}), Field::O);
// }

TEST_F(BoardTest, whenAskedAboutSizeOfTheBoardThen3IsReturned)
{
    Board sut;

    int expectedSize = 3;
    
    EXPECT_EQ(sut.sizeOfBoard(), expectedSize); 
}
