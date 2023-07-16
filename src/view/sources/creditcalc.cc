#include "../includes/creditcalc.h"

#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>

CreditCalc::CreditCalc(QWidget* parent) : QWidget(parent) {
  CreateWidgets();
  AddWidgets();
  SetWidgets();

  setLayout(main_layout);
}

void CreditCalc::CreateWidgets() {
  main_layout = new QGridLayout;

  amount_label = new QLabel(tr("Loan Amount"));
  term_label = new QLabel(tr("Loan Term"));
  rate_label = new QLabel(tr("Interest Rate"));
  compound_label = new QLabel(tr("Compound"));

  amount_line = new QLineEdit();
  term_y_line = new QLineEdit();
  term_m_line = new QLineEdit();
  rate_line = new QLineEdit();

  main_text = new QTextEdit();
  main_text->setReadOnly(true);

  calculate = new QPushButton(tr("CALCULATE"));

  compound_box = new QComboBox;

  connect(calculate, SIGNAL(clicked()), this, SLOT(CalcClicked()));
}

void CreditCalc::AddWidgets() {
  main_layout->addWidget(amount_label, 0, 0);
  main_layout->addWidget(term_label, 1, 0);
  main_layout->addWidget(rate_label, 3, 0);
  main_layout->addWidget(compound_label, 4, 0);

  main_layout->addWidget(amount_line, 0, 1);
  main_layout->addWidget(term_y_line, 1, 1);
  main_layout->addWidget(term_m_line, 2, 1);
  main_layout->addWidget(rate_line, 3, 1);

  main_layout->addWidget(main_text, 7, 0, 8, 2, Qt::AlignTop);

  main_layout->addWidget(calculate, 6, 0);

  main_layout->addWidget(compound_box, 4, 1);

  main_layout->setColumnStretch(0, 1);
  main_layout->setColumnStretch(1, 2);
}

void CreditCalc::SetWidgets() {
  compound_box->addItem(QString("annually"));
  compound_box->addItem(QString("monthly"));

  amount_line->setPlaceholderText(QString("$"));
  term_y_line->setPlaceholderText(QString("year"));
  term_m_line->setPlaceholderText(QString("month"));
  rate_line->setPlaceholderText(QString("%"));
}

void CreditCalc::CalcClicked() {
  main_text->clear();

  CheckEmptyLines();

  if (!main_text->toPlainText().isEmpty()) return;

  double amount = amount_line->text().toDouble();
  double year = term_y_line->text().toDouble();
  double month = term_m_line->text().toDouble();
  double rate = rate_line->text().toDouble();

  try {
    Controller c(amount, year, month, rate);
    Credit::type t =  compound_box->currentText() == QString("annually")
      ? Credit::Annually : Credit::Monthly;
    QString out = QString::fromStdString(c.CreditData(t));
    main_text->setPlainText(out);
  } catch (std::exception &e) {
    main_text->setPlainText(QString::fromStdString(e.what()));
  }
}

void CreditCalc::CheckEmptyLines() {
  if (amount_line->text().isEmpty()) {
    main_text->setPlainText(QString("Empty Amount"));
  } else if (term_y_line->text().isEmpty() && term_m_line->text().isEmpty()) {
    main_text->setPlainText(QString("Empty Term"));
  } else if (rate_line->text().isEmpty()) {
    main_text->setPlainText(QString("Empty Rate"));
  }
}

CreditCalc::~CreditCalc() {
  delete main_layout;

  delete amount_label;
  delete term_label;
  delete rate_label;
  delete compound_label;

  delete amount_line;
  delete term_y_line;
  delete term_m_line;
  delete rate_line;
  
  delete main_text;

  delete calculate;

  delete compound_box;
}
