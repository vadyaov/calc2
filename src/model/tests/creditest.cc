#include <gtest/gtest.h>

#include "../includes/credit.h"

using namespace s21;

TEST(credit_test, t1) {
  Credit c(500000.0, 7.0, 2, 0);
  std::string out = c.GetCreditInfo(Credit::type::Annually);
  std::string expected =
      "MONTH PAYMENT --> 22386.29\n"
      "TOTAL PAYMENT ----> 537270.95\n"
      "OVERPAYMENT ------> 37270.95";
  EXPECT_EQ(out, expected);
}

TEST(credit_test, t2) {
  Credit c(10000000.0, 11.2, 15, 0);
  std::string out = c.GetCreditInfo(Credit::type::Monthly);
  std::string expected =
      "MONTH PAYMENT --> \n\t from 148888.89\n\t   to 56074.08\n"
      "TOTAL PAYMENT ----> 18446666.67\n"
      "OVERPAYMENT ------> 8446666.67";
  EXPECT_EQ(out, expected);
}

TEST(credit_test, t1_throw) {
  EXPECT_THROW(
      {
        try {
          Credit m(-1000, 1, 2, 0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Negative value error", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(credit_test, t2_throw) {
  EXPECT_THROW(
      {
        try {
          Credit m(1000, -1, 2, 0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Negative value error", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(credit_test, t3_throw) {
  EXPECT_THROW(
      {
        try {
          Credit m(1000, 1, -2, 0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Negative value error", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(credit_test, t4_throw) {
  EXPECT_THROW(
      {
        try {
          Credit m(1000, 1, 2, -10);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Negative value error", e.what());
          throw;
        }
      },
      std::logic_error);
}

TEST(credit_test, t5_throw) {
  EXPECT_THROW(
      {
        try {
          Credit m(1000, 1, 0, 0);
        } catch (const std::logic_error& e) {
          EXPECT_STREQ("Term input error", e.what());
          throw;
        }
      },
      std::logic_error);
}
