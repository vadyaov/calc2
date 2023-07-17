#include "../includes/credit.h"

#include <cmath>
#include <stdexcept>

double RoundUp(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

s21::Credit::Credit(double am, double rat, double year, double month) : amount{am},
                                          rate{rat}, period{year * 12 + month} {

  if (std::signbit(amount) || std::signbit(rate) ||
      std::signbit(year) || std::signbit(month))
    throw std::logic_error("Negative value error");
  if (period == 0)
    throw std::logic_error("Term input error");
}

std::string s21::Credit::GetCreditInfo(type t) const {
  std::string data = "MONTH PAYMENT --> ";

  double month_payment, over_payment{0}, total_payment{0};

  if (t == Annually) {
    month_payment = (amount * rate / 1200.0) / (1 - std::pow(1 + rate / 1200, -period));
    total_payment = month_payment * period;
    data += std::to_string(RoundUp(month_payment, 2));
  } else {
    double first_month{0}, last_month{0};
    for (int i = 0; i < period; ++i) {

      month_payment = amount / period + (amount - (amount / period) * i) * (rate / 1200);
      total_payment += month_payment;

      if (0 == i) first_month = month_payment;
      else if (i == period - 1) last_month = month_payment;

    }

    data += "\n\t from " + std::to_string(RoundUp(first_month, 2)) +
            "\n\t   to " + std::to_string(RoundUp(last_month, 2));

  }
  over_payment = total_payment - amount;

  data += "\nTOTAL PAYMENT ----> " + std::to_string(RoundUp(total_payment, 2)) +
          "\nOVERPAYMENT ------> " + std::to_string(RoundUp(over_payment, 2));

  return data;
}
