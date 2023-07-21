#include <QApplication>
#include <QTabWidget>

#include "includes/creditcalc.h"
#include "includes/depositcalc.h"
#include "includes/smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);

  QTabWidget tabs;
  tabs.setWindowTitle("SmartCalc_v2.0");

  s21::SmartCalc calc;
  s21::CreditCalc credit;
  s21::DepositCalc deposit;

  tabs.addTab(&calc, QString("calc"));
  tabs.addTab(&credit, QString("credit"));
  tabs.addTab(&deposit, QString("deposit"));

#if defined(__APPLE__) && defined(__MACH__)
  tabs.setFixedSize(610, 750);
#else
  tabs.setFixedSize(610, 750);
#endif
  tabs.show();
  return a.exec();
}
