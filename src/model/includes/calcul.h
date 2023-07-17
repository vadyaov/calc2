#ifndef _MODEL_
#define _MODEL_

#include <string>

namespace s21 {
class Model {
  private:
    std::string expression;
  public:
    Model() = delete;
    explicit Model(const std::string&);
    ~Model() = default;
    double CalculateExpression(const double) const;
};
}  // namespace s21

#endif  // _MODEL_
