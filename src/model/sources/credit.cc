#include "../includes/credit.h"

#include <cmath>
#include <stdexcept>

double RoundUp(double value, int decimal_places) {
  const double multiplier = std::pow(10.0, decimal_places);
  return std::ceil(value * multiplier) / multiplier;
}

void RemoveTrailingZeros(std::string& str) {
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);
  str.erase(str.find_last_not_of('.') + 1, std::string::npos);
}

s21::Credit::Credit(double am, double rat, double year, double month)
    : amount{am}, rate{rat}, period{year * 12 + month} {
  if (std::signbit(amount) || std::signbit(rate) || std::signbit(year) ||
      std::signbit(month))
    throw std::logic_error("Negative value error");
  if (period == 0) throw std::logic_error("Term input error");
}

std::string s21::Credit::GetCreditInfo(type t) const {
  std::string data = "MONTH PAYMENT --> ";

  double month_payment, over_payment{0}, total_payment{0};

  if (t == Annually) {
    month_payment =
        (amount * rate / 1200.0) / (1 - std::pow(1 + rate / 1200, -period));
    total_payment = month_payment * period;

    std::string month_string = std::to_string(RoundUp(month_payment, 2));
    RemoveTrailingZeros(month_string);
    data += month_string;
  } else {
    double first_month{0}, last_month{0};
    for (int i = 0; i < period; ++i) {
      month_payment =
          amount / period + (amount - (amount / period) * i) * (rate / 1200);
      total_payment += month_payment;

      if (0 == i)
        first_month = month_payment;
      else if (i == period - 1)
        last_month = month_payment;
    }

    std::string f_month_string = std::to_string(RoundUp(first_month, 2));
    std::string l_month_string = std::to_string(RoundUp(last_month, 2));

    RemoveTrailingZeros(f_month_string);
    RemoveTrailingZeros(l_month_string);

    data += "\n\t from " + f_month_string + "\n\t   to " + l_month_string;
  }
  over_payment = total_payment - amount;

  std::string total_string = std::to_string(RoundUp(total_payment, 2));
  std::string over_string = std::to_string(RoundUp(over_payment, 2));

  RemoveTrailingZeros(total_string);
  RemoveTrailingZeros(over_string);

  data += "\nTOTAL PAYMENT ----> " + total_string + "\nOVERPAYMENT ------> " +
          over_string;

  return data;
}
