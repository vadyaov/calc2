#ifndef CR_CONTROLLER_H
#define CR_CONTROLLER_H

#include "../../model/includes/credit.h"

namespace s21 {
class CrController {
  Credit *c;

 public:
  CrController() = delete;
  CrController(double, double, double, double);
  ~CrController();

  std::string CreditData(Credit::type);
};
}  // namespace s21

#endif  // CR_CONTROLLER_H
