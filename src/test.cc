#include "model.h"

int main() {
  std::string str("1+2.1123/1.5-8mod5+sin(11)-atan(sin(5))");
  Model m{str};
  m.CalculateExpression();
  return 0;
}
