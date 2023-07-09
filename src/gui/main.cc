#include "smartcalc.h"
#include "creditcalc.h"
#include "depositcalc.h"

#include <QTabWidget>
#include <QApplication>

int main(int argc, char **argv) {
  QApplication a(argc, argv);

  QTabWidget tabs;
  SmartCalc calc;
  CreditCalc credit;
  DepositCalc deposit;
/* #if defined(__APPLE__) && defined(__MACH__) */
/* #else */
  tabs.addTab(&calc, QString("calc"));
  tabs.addTab(&credit, QString("credit"));
  tabs.addTab(&deposit, QString("deposit"));
  tabs.setFixedSize(610, 750);
/* #endif */
  tabs.show();
  return a.exec();
}
