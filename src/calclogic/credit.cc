#include "credit.h"

#include <cmath>
#include <stdexcept>

Credit::Credit(double am, double rat, double per) : amount{am}, rate{rat}, period{per} {
  if (std::signbit(amount) || std::signbit(rate) || std::signbit(period))
    throw std::logic_error("Negative value error");
  if (period == 0)
    throw std::logic_error("Term input error");
}

std::string Credit::GetCreditInfo(type t) const {
  std::string data = "Month Payment: ";

  double month_payment {0}, over_payment{0}, total_payment{0},
         first_month{0}, last_month{0};

  if (t == Annually) {
    month_payment = (amount * rate / 1200.0) / (1 - std::pow(1 + rate / 1200, -period));
    total_payment = month_payment * period;
    data += std::to_string(month_payment);
  } else {
    for (int i = 0; i < period; ++i) {

      month_payment = amount / period + (amount - (amount / period) * i) * (rate / 1200);
      total_payment += month_payment;

      if (0 == i) first_month = month_payment;
      else if (i == period - 1) last_month = month_payment;

    }

    data += "\n\t from:";
    data += std::to_string(first_month);
    data += "\n\t  to:   ";
    data += std::to_string(last_month);

  }
  over_payment = total_payment - amount;

  data += "\nTotal Payment: ";
  data += std::to_string(total_payment);
  data += "\nOverpayment:  ";
  data += std::to_string(over_payment);

  return data;
}
