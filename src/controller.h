#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "./calclogic/model.h"

class Controller {
  private:
    Model m;
  public:
    explicit Controller(const std::string& exp) : m(exp) {}
    ~Controller() = default;

    double Calculate(const double x) const { return m.CalculateExpression(x); }

};

#endif //  CONTROLLER_H
