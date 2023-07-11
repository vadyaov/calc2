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
  SetWidgets();

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
  capitalization = new QLabel(tr("Capitalization"));

  amount_line = new QLineEdit;
  rate_line = new QLineEdit;
  tax_line = new QLineEdit;
  repl_amount_line = new QLineEdit;
  remove_amount_line = new QLineEdit;

  main_text = new QTextEdit;

  calculate = new QPushButton(tr("Calculate"));


  payment_freq_box = new QComboBox;
  depo_repl_box = new QComboBox;
  depo_remove_box = new QComboBox; 
  cap_box = new QComboBox;
   
  first_day = new QDateEdit;
  last_day = new QDateEdit;

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
  main_layout->addWidget(cap_box, 6, 1);

  main_layout->addLayout(date_layout, 1, 1, 1, 2);

  date_layout->addWidget(first_day, 0);
  date_layout->addWidget(last_day, 1, Qt::AlignLeft);

  main_layout->setColumnStretch(0, 1);
  main_layout->setColumnStretch(1, 1);
}

void DepositCalc::CalcClicked() {
  // CheckEmptyLines()
}

void DepositCalc::SetWidgets() {
  SetComboBoxItems();
  
  first_day->setDisplayFormat(QString("dd.MM.yyyy"));
  last_day->setDisplayFormat(QString("dd.MM.yyyy"));
  first_day->setMinimumDate(QDate::currentDate());
  last_day->setMinimumDate(QDate::currentDate());

  tax_line->setPlaceholderText(QString("%"));
  rate_line->setPlaceholderText(QString("%"));
  amount_line->setPlaceholderText(QString("$"));
  repl_amount_line->setPlaceholderText(QString("$"));
  remove_amount_line->setPlaceholderText(QString("$"));
}

void DepositCalc::SetComboBoxItems() {
  payment_freq_box->addItem(QString("day"));
  payment_freq_box->addItem(QString("week"));
  payment_freq_box->addItem(QString("1 month"));
  payment_freq_box->addItem(QString("quarter"));
  payment_freq_box->addItem(QString("6 month"));
  payment_freq_box->addItem(QString("1 year"));

  depo_repl_box->addItem(QString("--"));
  depo_repl_box->addItem(QString("1 month"));
  depo_repl_box->addItem(QString("2 month"));
  depo_repl_box->addItem(QString("quarter"));
  depo_repl_box->addItem(QString("4 month"));
  depo_repl_box->addItem(QString("6 month"));
  depo_repl_box->addItem(QString("1 year"));

  depo_remove_box->addItem(QString("--"));
  depo_remove_box->addItem(QString("1 month"));
  depo_remove_box->addItem(QString("2 month"));
  depo_remove_box->addItem(QString("quarter"));
  depo_remove_box->addItem(QString("4 month"));
  depo_remove_box->addItem(QString("6 month"));
  depo_remove_box->addItem(QString("1 year"));

  cap_box->addItem(QString("NO"));
  cap_box->addItem(QString("YES"));
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
  delete cap_box;
   
  delete first_day;
  delete last_day;

  delete date_layout;
  delete main_layout;
}
