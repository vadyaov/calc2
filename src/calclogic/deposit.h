#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <tuple>
#include <string>

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

struct Profit {
  double income;
  double deposit;
  double tax;

  Profit(double in, double dep, double t) : income{in}, deposit{dep}, tax{t} {}
  Profit(const Profit& other) : income{other.income}, deposit{other.deposit},
                                tax{other.tax} {}
};

class Deposit {
  Amount amounts;
  Rate rates;
  std::size_t period; // in days

  public:
    using F = enum Frequency {NO = 0, DAY, WEEK, MONTH1, MONTH2, QUARTER, MONTH4, MONTH6, YEAR};

    Deposit() = delete;
    Deposit(const Amount& a, const Rate& r, std::size_t p) : amounts{a},
                                                              rates{r},
                                                              period{p} {}
    ~Deposit() = default;

    Profit CalculateProfit(F pay, F replanish, F withdraw, bool cap);

    std::size_t days() {return period;}

};

std::size_t Days(const std::pair<std::string, std::string>&);

#endif // DEPOSIT_H 
