#include <gtest/gtest.h>
#include "../includes/deposit.h"

using namespace s21;
using str_pair = std::pair<std::string, std::string>;

TEST(deposit_test, t1) {
  std::string start = "12.11.2023", end = "12.11.2024";
  Deposit d(Amount(350000.0, 0, 0), Rate(4.7, 30), Days(str_pair(start, end)));
  std::string out = d.CalculateProfit(Deposit::F::QUARTER, Deposit::F::NO, Deposit::F::NO, false);
  std::string expected = " INCOME ---> 16450.01"
                         "\nDEPOSIT --> 350000"
                         "\n        TAX ---> 4935.01";
  EXPECT_EQ(out, expected);
}

TEST(deposit_test, t2) {
  std::string start = "12.11.2023", end = "17.10.2026";
  Deposit d(Amount(500000.0, 20000, 0), Rate(4.7, 30), Days(str_pair(start, end)));
  std::string out = d.CalculateProfit(Deposit::F::MONTH1, Deposit::F::MONTH6, Deposit::F::NO, false);
  std::string expected = " INCOME ---> 75532.22"
                         "\nDEPOSIT --> 600000"
                         "\n        TAX ---> 22659.67";
  EXPECT_EQ(out, expected);
}


TEST(deposit_test, t3) {
  std::string start = "12.11.2023", end = "17.10.2026";
  Deposit d(Amount(500000.0, 20000, 15000), Rate(4.7, 30), Days(str_pair(start, end)));
  std::string out = d.CalculateProfit(Deposit::F::WEEK, Deposit::F::MONTH2,
                    Deposit::F::QUARTER, true);
  std::string expected = " INCOME ---> 86035.31"
                         "\nDEPOSIT --> 760643.53"
                         "\n        TAX ---> 25810.6";
  EXPECT_EQ(out, expected);
}

