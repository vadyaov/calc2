#include "smartcalc.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  SmartCalc calc;
/* #if defined(__APPLE__) && defined(__MACH__) */
/*   calc.setMinimumWidth(650); */
/*   calc.setMinimumHeight(720); */
/*   calc.setMaximumWidth(650); */
/*   calc.setMaximumHeight(720); */
/* #else */
  calc.setFixedSize(610, 750);
/* #endif */
  calc.show();
  return a.exec();
}
