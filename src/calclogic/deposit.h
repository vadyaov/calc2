#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <tuple>
#include <string>
#include <iostream>

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

  public:                  // 0    1     2     3        4       5        6     7        8
    using F = enum Frequency {NO, DAY, WEEK, MONTH1, MONTH2, QUARTER, MONTH4, MONTH6, YEAR};

    Deposit() = delete;
    Deposit(const Amount& a, const Rate& r, std::size_t p) : amounts{a},
                                                              rates{r},
                                                              period{p} {
      std::cout << "deposit amount: " << amounts.dep_amount <<
                 "\nreplani amount: " << amounts.rep_amount <<
                 "\nremove  amount: " << amounts.rem_amount << std::endl;

      std::cout << "\nRate : " << rates.dep_rate << "\nTax:  " << rates.tax_rate << std::endl;

      std::cout << "\nPeriod: " << p << std::endl;

    }
    ~Deposit() = default;

    std::string CalculateProfit(F pay, F replanish, F withdraw, bool cap);

    std::size_t days() {return period;}

};

std::size_t Days(const std::pair<std::string, std::string>&);
Deposit::F FindCorrectIdx(int);

#endif // DEPOSIT_H 
