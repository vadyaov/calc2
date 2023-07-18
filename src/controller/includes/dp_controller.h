#ifndef DP_CONTROLLER_H
#define DP_CONTROLLER_H

#include "../../model/includes/deposit.h"

namespace s21 {
class DpController {
  private:
    Deposit* d;
  public:
    using pair = std::pair<std::string, std::string>;

    DpController() = delete;

    DpController(const Amount&, const Rate&, const pair&);

    ~DpController();

    std::string DepositData(bool, int, int, int);

};
}  // namespace s21

#endif  // DP_CONTROLLER_H

