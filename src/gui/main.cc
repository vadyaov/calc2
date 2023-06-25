#include "smartcalc.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  SmartCalc calc;
  calc.show();
  return a.exec();
}
