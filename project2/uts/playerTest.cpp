#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "player.hpp"
#include "field.hpp"




class PlayerTest : public ::testing::Test
{
    
    protected:
    PlayerTest() {};
    ~PlayerTest() override {};

    void SetUp() override {};
    void TearDown() override {};
    
};


TEST_F(PlayerTest, whenAskedAboutPlayersSymbolShouldReturnX)
{

    Player sut{Field::X};
    EXPECT_EQ(sut.getSymbol(), Field::X);
}

TEST_F(PlayerTest, whenCorrectInputIsGivenShouldChangeTheStateOfTheBoardAndReturnTrue)
{
    Player sut{Field::X};
    EXPECT_TRUE(sut.makeMove());
    
}
