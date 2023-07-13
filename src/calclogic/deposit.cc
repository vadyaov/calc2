#include "deposit.h"

#include <utility>
#include <cmath>
#include <iostream>

struct Date {
  int day = 0;
  int month = 0;
  int year = 0;

  /* only 'dd.MM.yyy' format */
  explicit Date(const std::string& date) {
    day += (date[0] - '0') * 10 + (date[1] - '0');
    month += (date[3] - '0') * 10 + (date[4] - '0');
    year += (date[6] - '0') * 1000 + (date[7] - '0') * 100 +
            (date[8] - '0') * 10 + (date[9] - '0');
  }

  std::size_t Yulian() {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    std::size_t jdn =
      day + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    return jdn;
  }
};

static double Period(Deposit::Frequency f) {
  const double avg_days_in_month = 30.4167;
  const double r[] = {0.0,
                      1.0,
                      7.0, 
                      avg_days_in_month,
                      avg_days_in_month * 2,
                      avg_days_in_month * 3,
                      avg_days_in_month * 4,
                      avg_days_in_month * 6,
                      avg_days_in_month * 12};
  return r[f];
}

std::string Deposit::CalculateProfit(F pay, F replanish, F withdraw, bool cap) {
  std::size_t i = 0, ii = 1, jj = 1, kk = 1;
  double percents {0};

  double day_percent = rates.dep_rate / 365.0 / 100.0;
  double cap_period = Period(pay), add_period = Period(replanish),
         rem_period = Period(withdraw);

  double income{0}, tax{0};

  std::cout << cap_period << ' ' << add_period << ' ' << rem_period << std::endl;

  while (i < period) {
    percents += amounts.dep_amount * day_percent;
    if (cap && i == static_cast<std::size_t>(cap_period * ii)) {
      amounts.dep_amount += percents;
      income += percents;
      percents = 0.0;
      ++ii;
    }
    if (replanish != F::NO && i == static_cast<std::size_t>(add_period * jj)) {
      if (jj++ < static_cast<std::size_t>(period / add_period))
        amounts.dep_amount += amounts.rep_amount;
    }
    if (withdraw != F::NO && i == static_cast<std::size_t>(rem_period * kk)) {
      if (kk++ < static_cast<std::size_t>(period / rem_period))
        amounts.dep_amount -= amounts.rem_amount;
    }
    ++i;
  }

  if (i == period && cap) amounts.dep_amount += percents;
  income += percents;

  std::string result {"Income: "};                                       
  result += std::to_string(std::floor(income));                                 
  result += "\nDeposit: ";                                            
  result += std::to_string(std::floor(amounts.dep_amount));                                
  result += "\nTax    : ";                                            
  result += std::to_string(std::floor(income * rates.tax_rate / 100.0));

  std::cout << result << std::endl;

  return result;
}


std::size_t Days(const std::pair<std::string, std::string>& dates) {
  Date start(dates.first), end(dates.second);
  return end.Yulian() - start.Yulian();
}

Deposit::F FindCorrectIdx(int i) {
  if (i < 3) return Deposit::F(i + 1);
  if (i == 3) return Deposit::F(i + 2);
  
  return Deposit::F(i + 3);
}
