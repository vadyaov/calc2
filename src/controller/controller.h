#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/includes/calcul.h"
#include "../model/includes/credit.h"
#include "../model/includes/deposit.h"

namespace s21 {
class Controller {
  private:
    Model *m;
    Credit *c;
    Deposit* d;
  public:
    using pair = std::pair<std::string, std::string>;

    Controller() = delete;

    explicit Controller(const std::string&);

    Controller(double, double, double, double);

    Controller(const Amount&, const Rate&, const pair&);

    ~Controller();

    double Calculate(const double) const;

    std::string CreditData(Credit::type);

    std::string DepositData(bool, int, int, int);

};
}  // namespace s21

#endif //  CONTROLLER_H
