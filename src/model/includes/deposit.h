#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <string>

namespace s21 {
struct Amount {
  double dep_amount;
  double rep_amount;
  double rem_amount;

  Amount(double dep, double rep, double rem) : dep_amount{dep}, rep_amount{rep},
                                               rem_amount{rem} {}

  Amount(const Amount& other) : dep_amount{other.dep_amount},
                                rep_amount{other.rep_amount},
                                rem_amount{other.rem_amount} {}
};

struct Rate {
  double dep_rate;
  double tax_rate;

  Rate(double dep, double tax) : dep_rate{dep}, tax_rate{tax} {}
  Rate(const Rate& other) : dep_rate{other.dep_rate}, tax_rate{other.tax_rate} {}
};

class Deposit {
  Amount amounts;
  Rate rates;
  std::size_t period; // in days

  public:
    using F = enum Frequency {NO, DAY, WEEK, MONTH1, MONTH2, QUARTER, MONTH4, MONTH6, YEAR};

    Deposit() = delete;
    Deposit(const Amount&, const Rate&, std::size_t);
    ~Deposit() = default;

    std::string CalculateProfit(F, F, F, bool);

};
}  // namespace s21

std::size_t Days(const std::pair<std::string, std::string>&);
s21::Deposit::F FindCorrectIdx(int);

#endif // DEPOSIT_H 
