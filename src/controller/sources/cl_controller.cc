#include "../includes/cl_controller.h"

s21::ClController::ClController(const std::string& exp)
    : m{new Calculator(exp)} {}

s21::ClController::~ClController() { delete m; }

double s21::ClController::Calculate(const double x) const {
  return m->CalculateExpression(x);
}
