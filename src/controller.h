#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <tuple>
#include <utility>

#include "calclogic/model.h"
#include "calclogic/credit.h"
#include "calclogic/deposit.h"

class Controller {
  private:
    Model *m;
    Credit *c;
    Deposit* d;
  public:
    using triple = std::tuple<double, double, double>;
    using pair = std::pair<std::string, std::string>;

    Controller() = delete;
    explicit Controller(const std::string& exp) : m{new Model(exp)}, c{nullptr}, d{nullptr} {
    }

    Controller(double x, double y, double z) : m{nullptr}, c{new Credit(x, y, z)}, d{nullptr} {
    }

    Controller(const Amount& a, const Rate& r, const pair& p) : m {nullptr},
                                    c{nullptr}, d(new Deposit(a, r, Days(p))) {}

    ~Controller() {
      delete m;
      delete c;
      delete d;
    }

    double Calculate(const double x) const { return m->CalculateExpression(x); }

    std::string CreditData(Credit::type t) { return c->GetCreditInfo(t); }

    std::string DepositData(bool capitalization, int pay_idx, int repl_idx = 0,
                            int rem_idx = 0) {

      Deposit::F pay_freq = FindCorrectIdx(pay_idx);
      Deposit::F repl_freq = repl_idx == 0 ? Deposit::F::NO : Deposit::F(repl_idx + 2);
      Deposit::F rem_freq = rem_idx == 0 ? Deposit::F::NO : Deposit::F(rem_idx + 2);

      std::cout << pay_freq << ' ' << repl_freq << ' ' << rem_freq << std::endl;

      std::string result = d->CalculateProfit(pay_freq, repl_freq, rem_freq, capitalization);

      return result;
    }


};

#endif //  CONTROLLER_H
