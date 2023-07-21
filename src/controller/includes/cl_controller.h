#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../../model/includes/calcul.h"

namespace s21 {
class ClController {
 private:
  Calculator *m;

 public:
  using pair = std::pair<std::string, std::string>;

  ClController() = delete;

  explicit ClController(const std::string &);

  ~ClController();

  double Calculate(const double) const;
};
}  // namespace s21

#endif  //  CONTROLLER_H
