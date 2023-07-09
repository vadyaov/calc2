#include "depositcalc.h"

#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QDateEdit>
#include <QComboBox>
#include <QHBoxLayout>


DepositCalc::DepositCalc(QWidget* parent) : QWidget(parent) {
  CreateWidgets();
  AddWidgets();

  setLayout(main_layout);
}

void DepositCalc::CreateWidgets() {
  main_layout = new QGridLayout();
  
  amount_label = new QLabel(tr("Deposit Amount"));
  term_label = new QLabel(tr("Deposit Term"));
  rate_label = new QLabel(tr("Interest Rate"));
  tax_label = new QLabel(tr("Tax Rate"));
  freq_label = new QLabel(tr("Frequency of Payments"));
  depo_repl_label = new QLabel(tr("Depo Replanishment"));
  repl_amount_label = new QLabel(tr("Replanish Amount"));
  withdrawals_label = new QLabel(tr("Partial Withdrawals"));
  remove_amount_label = new QLabel(tr("Remove Amount"));

  amount_line = new QLineEdit;
  rate_line = new QLineEdit;
  tax_line = new QLineEdit;
  repl_amount_line = new QLineEdit;
  remove_amount_line = new QLineEdit;

  main_text = new QTextEdit;

  calculate = new QPushButton(tr("Calculate"));

  capitalization = new QRadioButton(tr("Capitalization"));

  payment_freq_box = new QComboBox;
  depo_repl_box = new QComboBox;
  depo_remove_box = new QComboBox; 
   
  first_day = new QDateEdit;
  last_day = new QDateEdit;

  first_day->setMaximumWidth(130);
  last_day->setMaximumWidth(130);

  date_layout = new QHBoxLayout;
}

void DepositCalc::AddWidgets() {
  main_layout->addWidget(amount_label, 0, 0);
  main_layout->addWidget(term_label, 1, 0);
  main_layout->addWidget(rate_label, 3, 0);
  main_layout->addWidget(tax_label, 4, 0);
  main_layout->addWidget(freq_label, 5, 0);
  main_layout->addWidget(depo_repl_label, 7, 0);
  main_layout->addWidget(repl_amount_label, 8, 0);
  main_layout->addWidget(withdrawals_label, 9, 0);
  main_layout->addWidget(remove_amount_label, 10, 0);

  main_layout->addWidget(amount_line, 0, 1);
  main_layout->addWidget(rate_line, 3, 1);
  main_layout->addWidget(tax_line, 4, 1);
  main_layout->addWidget(repl_amount_line, 8, 1);
  main_layout->addWidget(remove_amount_line, 10, 1);

  main_layout->addWidget(main_text, 12, 0, 12, 2, Qt::AlignTop);

  main_layout->addWidget(calculate, 11, 0);

  main_layout->addWidget(capitalization, 6, 0);

  main_layout->addWidget(payment_freq_box, 5, 1);
  main_layout->addWidget(depo_repl_box, 7, 1);
  main_layout->addWidget(depo_remove_box, 9, 1);

  main_layout->addLayout(date_layout, 1, 1, 1, 2);

  date_layout->addWidget(first_day, 0);//, Qt::AlignLeft);
  date_layout->addWidget(last_day, 1, Qt::AlignLeft);

  main_layout->setColumnStretch(0, 1);
  main_layout->setColumnStretch(1, 1);
}

void DepositCalc::CalcClicked() {
}

DepositCalc::~DepositCalc() {

  delete amount_label;
  delete term_label;
  delete rate_label;
  delete tax_label;
  delete freq_label;
  delete depo_repl_label;
  delete repl_amount_label;
  delete withdrawals_label;
  delete remove_amount_label;
                     
  delete amount_line;
  delete rate_line;
  delete tax_line;
  delete repl_amount_line;
  delete remove_amount_line;
                     
  delete main_text;
                     
  delete calculate;
                     
  delete capitalization;
                     
  delete payment_freq_box;
  delete depo_repl_box;
  delete depo_remove_box;
   
  delete first_day;
  delete last_day;

  delete date_layout;
  delete main_layout;
}
