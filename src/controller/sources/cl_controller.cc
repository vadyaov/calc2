#include "../includes/cl_controller.h"

using namespace s21;

ClController::ClController(const std::string& exp) : m{new Calculator(exp)} {
}

ClController:: ~ClController() {
  delete m;
}

double ClController::Calculate(const double x) const {
  return m->CalculateExpression(x);
}

