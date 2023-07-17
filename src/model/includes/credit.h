#ifndef CREDIT_H
#define CREDIT_H

#include <string>

namespace s21 {
class Credit {
  double amount;
  double rate;
  double period;

  public:
    enum type {Annually, Monthly};

    Credit() = delete;
    Credit(double, double, double, double);
    ~Credit() = default;

    std::string GetCreditInfo(type t) const;
};
}  // namespace s21

#endif //  CREDIT_H
