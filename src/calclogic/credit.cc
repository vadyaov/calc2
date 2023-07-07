#include "credit.h"

#include <cmath>
#include <stdexcept>

Credit::Credit() : amount{0}, rate{0}, period{0} {}

Credit::Credit(double am, double rat, double per) : amount{am}, rate{rat}, period{per} {
  if (std::signbit(amount) || std::signbit(rate) || std::signbit(period))
    throw std::logic_error("Negative value error");
}
