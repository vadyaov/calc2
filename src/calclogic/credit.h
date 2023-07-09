#ifndef CREDIT_H
#define CREDIT_H

#include <string>

class Credit {
  double amount;
  double rate;
  double period;

  public:
    enum type {Annually, Monthly};

    Credit() = delete;
    Credit(double, double, double);
    ~Credit() = default;

    std::string GetCreditInfo(type t) const;
};

#endif //  CREDIT_H
