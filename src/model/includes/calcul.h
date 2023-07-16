#ifndef _MODEL_
#define _MODEL_

#include <string>

class Model {
  private:
    std::string expression;
  public:
    Model() = delete;
    explicit Model(const std::string&);
    ~Model() = default;
    double CalculateExpression(const double) const;
};

#endif  // _MODEL_
