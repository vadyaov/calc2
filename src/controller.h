#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "calclogic/model.h"
#include "calclogic/credit.h"

class Controller {
  private:
    Model m;
    Credit c;
  public:
    explicit Controller(const std::string& exp) : m(exp), c{} {}
    Controller(double x, double y, double z) : m{}, c(x, y, z) {}
    ~Controller() = default;

    double Calculate(const double x) const { return m.CalculateExpression(x); }


};

#endif //  CONTROLLER_H
