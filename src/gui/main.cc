#include "smartcalc.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  SmartCalc calc;
/* #if defined(__APPLE__) && defined(__MACH__) */
/* #else */
  calc.setFixedSize(610, 750);
/* #endif */
  calc.show();
  return a.exec();
}
