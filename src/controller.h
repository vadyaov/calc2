#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "calclogic/credit.h"
#include "calclogic/model.h"

class Controller {
  private:
    Model *m;
    Credit *c;
  public:
    Controller() = delete;
    explicit Controller(const std::string& exp) : m{new Model(exp)}, c{nullptr} {
    }

    Controller(double x, double y, double z) : m{nullptr}, c{new Credit(x, y, z)} {
    }

    ~Controller() {
      delete m;
      delete c;
    }

    double Calculate(const double x) const { return m->CalculateExpression(x); }
    std::string CreditData(Credit::type t) { return c->GetCreditInfo(t); }


};

#endif //  CONTROLLER_H
