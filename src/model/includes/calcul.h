#ifndef _MODEL_
#define _MODEL_

#include <string>

namespace s21 {
class Calculator {
    std::string expression;
  public:
    explicit Calculator(const std::string&);
    double CalculateExpression(const double) const;
};
}  // namespace s21

#endif  // _MODEL_
