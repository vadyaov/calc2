#include "deposit.h"

#include <utility>
#include <cmath>

struct Date {
  int day = 0;
  int month = 0;
  int year = 0;

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

Profit Deposit::CalculateProfit(F pay, F replanish, F withdraw, bool cap) {

  return Profit(0, 0, 0);
}


std::size_t Days(const std::pair<std::string, std::string>& dates) {
  Date start(dates.first), end(dates.second);
  return end.Yulian() - start.Yulian();
}

