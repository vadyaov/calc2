#include <gtest/gtest.h>

#include <cmath>

#include "../includes/calcul.h"

using namespace s21;

TEST(calc_test, t1) {
  Calculator m("-2 * sin(30)/cos(30) -(-1) + sqrt(16/4)/tan( 1/2)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected = -2 * sin(30) / cos(30) - (-1) + sqrt(16 / 4) / tan(1.0 / 2.0);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t2) {
  Calculator m("+2 * asin(-0.56)/acos(0.123)+ ln(16.0/4.0)/log( 1.0/2.0)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected =
      +2 * asin(-0.56) / acos(0.123) + log(16.0 / 4.0) / log10(1.0 / 2.0);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t3) {
  Calculator m("+2 * atan(-0.56)/sqrt(144.144)+-3 * 10.0 mod 3.0");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected = +2 * atan(-0.56) / sqrt(144.144) + -3 * fmod(10.0, 3.0);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t4) {
  Calculator m("2 ^ 3 ^ 2");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected = pow(2.0, pow(3.0, 2.0));
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t5) {
  Calculator m("cos( 9.456+ 909  /sin((-1  )*ln(2.3  ))) + 5689.98 ^ (-1.9)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected = cos(9.456 + 909 / sin((-1) * log(2.3))) + pow(5689.98, (-1.9));
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t6) {
  Calculator m(
      "tan(6.08123 /log(   5.6321 + 345 * (-x) *(-13.111))   ) /ln(45.32 / "
      "(+99.1334)   )^(+2)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(5.2345);
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) /
             pow(log(45.32 / (+99.1334)), 2);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t7) {
  Calculator m(
      "asin(0.256) * acos(-0.3456) / atan(0.000023456) + (2345.667 ^ (0.5) - "
      "12.3)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.0);
  expected = asin(0.256) * acos(-0.3456) / atan(0.000023456) +
             (pow(2345.667, 0.5) - 12.3);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t8) {
  Calculator m(
      "tan(6.08123/log(   5.6321 + 345 * (-x) *(-13.111))   ) /ln(45.32 / "
      "(+99.1334)   )^(+2)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(5.2345);
  expected = tan(6.08123 / log10(5.6321 + 345 * (-5.2345) * (-13.111))) /
             pow(log(45.32 / (+99.1334)), 2);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t9) {
  Calculator m(
      "555.666 mod 3.456 + ( ( atan(0.9876/x) + (-asin(0.222)  )  )  * cos((x "
      "* 3) ^ (  0.7889 ) ) - 2222.2 / (-777.7 ) )");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(17.239);
  expected = fmod(555.666, 3.456) + ((atan(0.9876 / 17.239) + (-asin(0.222))) *
                                         cos(pow(17.239 * 3, 0.7889)) -
                                     2222.2 / (-777.7));
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t10) {
  Calculator m(
      "-1678.2322 * x +  sqrt( log  (38.38 /24.55 ) + ln(58.2 - (-300.4))) * x "
      "* x * (-x)");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(0.009);
  expected =
      -1678.2322 * 0.009 + sqrt(log10(38.38 / 24.55) + log(58.2 - (-300.4))) *
                               0.009 * 0.009 * (-0.009);
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t11) {
  Calculator m(
      "678.987 * sin ( 23.2 -  6.7 +  sin(x *   x) -9.789 * cos(22.37/2.32)) + "
      "tan(342.35 ^ 0.7) + sin ( 23.2 -  6.7 +  sin(x *   x)"
      "* cos(22.37/2.32) + tan(-3.4235))");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(17.239);
  expected =
      678.987 *
          sin(23.2 - 6.7 + sin(17.239 * 17.239) - 9.789 * cos(22.37 / 2.32)) +
      tan(pow(342.35, 0.7)) +
      sin(23.2 - 6.7 + sin(17.239 * 17.239) * cos(22.37 / 2.32) + tan(-3.4235));
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t12) {
  Calculator m(
      "-(-87.543*sin(0.999+tan(x)-2.234))-50.66*(acos(0.234)/atan(0.55))");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(55.5);
  expected = -(-87.543 * sin(0.999 + tan(55.5) - 2.234)) -
             50.66 * (acos(0.234) / atan(0.55));
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t13) {
  Calculator m("2.15*sin(30)/1e2");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(55.5);
  expected = 2.15 * sin(30) / 1e2;
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t14) {
  Calculator m("2.15*sin(30)/1e-2");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(55.5);
  expected = 2.15 * sin(30) / 1e-2;
  ASSERT_EQ(result, expected);
}

TEST(calc_test, t15) {
  Calculator m("2.15*sin(30)/1e-2 + 1.45/4.23e-1");
  double result = 0.0, expected = 0.0;
  result = m.CalculateExpression(55.5);
  expected = 2.15 * sin(30) / 1e-2 + 1.45 / 4.23e-1;
  ASSERT_EQ(result, expected);
}

TEST(calc_test, e1) {
  EXPECT_THROW(
      {
        try {
          Calculator m(".3");
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e2) {
  EXPECT_THROW(
      {
        try {
          Calculator m("1 + sin(3.)");
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e3) {
  EXPECT_THROW(
      {
        try {
          Calculator m("1 + sin(.)");
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e4) {
  EXPECT_THROW(
      {
        try {
          Calculator m("sin()");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e5) {
  EXPECT_THROW(
      {
        try {
          Calculator m("sin(3)cos11)/15");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e6) {
  EXPECT_THROW(
      {
        try {
          Calculator m("+-/sin*(3)//cos11)/15");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e7) {
  EXPECT_THROW(
      {
        try {
          Calculator m("35/+*///mod1-+");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e8) {
  EXPECT_THROW(
      {
        try {
          Calculator m("sin((--1(()()))))");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e9) {
  EXPECT_THROW(
      {
        try {
          Calculator m("sin cos + tan log((()) -");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e10) {
  EXPECT_THROW(
      {
        try {
          Calculator m("3...44.5..2..23.4..5.5.5.3.4.3.4.");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e11) {
  EXPECT_THROW(
      {
        try {
          Calculator m("sin((((((((((((((1)");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e12) {
  EXPECT_THROW(
      {
        try {
          Calculator m("-------sin-------((((((((((((((++-++1)++++++++");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e13) {
  EXPECT_THROW(
      {
        try {
          Calculator m("e-1");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e14) {
  EXPECT_THROW(
      {
        try {
          Calculator m("1e");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(calc_test, e15) {
  EXPECT_THROW(
      {
        try {
          Calculator m("1.28eee-1");
          m.CalculateExpression(0.0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Invalid expression", e.what());
          throw;
        }
      },
      std::logic_error);
}
