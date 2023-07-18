#include "../includes/dp_controller.h"

s21::DpController::DpController(const Amount& a, const Rate& r, const pair& p) :
  d(new Deposit(a, r, Days(p))) {}


std::string s21::DpController::DepositData(bool capitalization, int pay_idx,
                                    int repl_idx, int rem_idx) {

  s21::Deposit::F pay_freq = FindCorrectIdx(pay_idx);
  s21::Deposit::F repl_freq = repl_idx == 0 ? Deposit::F::NO : Deposit::F(repl_idx + 2);
  s21::Deposit::F rem_freq = rem_idx == 0 ? Deposit::F::NO : Deposit::F(rem_idx + 2);

  std::string result = d->CalculateProfit(pay_freq, repl_freq, rem_freq, capitalization);

  return result;
}

s21::DpController::~DpController() {delete d;}
