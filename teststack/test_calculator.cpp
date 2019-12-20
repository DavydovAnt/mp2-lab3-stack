#include "gtest.h"

#include "../mp2-lab3-stack/Calculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c);
}



TEST(TCalculator, can_set_and_get_string)
{
	TCalculator  c;
	std::string expr = "2+2";
	ASSERT_NO_THROW(c.SetExpr(expr));
	EXPECT_EQ(c.GetExpr(), expr);
}



TEST(TCalculator, can_check_the_brackets_in_the_string)
{
	TCalculator c;
	c.SetExpr("(2+2)/3");
	EXPECT_EQ(true, c.check());
	c.SetExpr(")4+4");
	EXPECT_EQ(false, c.check());
}

TEST(TCalculator, can_convert_into_postfix)
{
	TCalculator c;
	c.SetExpr("1+2-3");
	c.ToPostfix();
	EXPECT_EQ(c.GetPostfix(), "1 2 +3-");
}

TEST(TCalculator, can_count_the_expression)
{
	TCalculator c;
	c.SetExpr("1+2-3");
	c.ToPostfix();
	EXPECT_EQ(c.Calc(), 0);
}

TEST(TCalculator, throws_when_try_to_count_an_incorrect_expression)
{
	TCalculator c;
	c.SetExpr("2/-3");
	c.ToPostfix();
	ASSERT_ANY_THROW(c.Calc());
}