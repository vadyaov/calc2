#include "../includes/cr_controller.h"

s21::CrController::CrController(double a, double y, double m, double r)
    : c{new Credit(a, r, y, m)} {}

s21::CrController::~CrController() { delete c; }

std::string s21::CrController::CreditData(Credit::type t) {
  return c->GetCreditInfo(t);
}
