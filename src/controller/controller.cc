#include "controller.h"

using namespace s21;

Controller::Controller(const std::string& exp) : m{new Model(exp)}, c{nullptr}, d{nullptr} {
}

Controller::Controller(double a, double y, double m, double r) : m{nullptr}, c{new Credit(a, r, y, m)}, d{nullptr} {}

Controller:: Controller(const Amount& a, const Rate& r, const pair& p) : m {nullptr}, c{nullptr}, d(new Deposit(a, r, Days(p))) {}

Controller:: ~Controller() {
  delete m;
  delete c;
  delete d;
}

double Controller::Calculate(const double x) const {
  return m->CalculateExpression(x);
}

std::string Controller::CreditData(Credit::type t) {
  return c->GetCreditInfo(t);
}

std::string Controller::DepositData(bool capitalization, int pay_idx,
                                    int repl_idx, int rem_idx) {

  Deposit::F pay_freq = FindCorrectIdx(pay_idx);
  Deposit::F repl_freq = repl_idx == 0 ? Deposit::F::NO : Deposit::F(repl_idx + 2);
  Deposit::F rem_freq = rem_idx == 0 ? Deposit::F::NO : Deposit::F(rem_idx + 2);

  std::string result = d->CalculateProfit(pay_freq, repl_freq, rem_freq, capitalization);

  return result;
}
