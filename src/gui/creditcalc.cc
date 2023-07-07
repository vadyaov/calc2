#include "creditcalc.h"

CreditCalc::CreditCalc(QWidget* parent) : QWidget(parent) {
  CreateWidgets();
  AddWidgets();

  connect(calculate, SIGNAL(clicked()), this, SLOT(CalcClicked()));

  setLayout(main_layout);
}

void CreditCalc::CreateWidgets() {
  main_layout = new QGridLayout();

  amount_label = new QLabel(tr("Loan Amount"));
  term_label = new QLabel(tr("Loan Term"));
  rate_label = new QLabel(tr("Interest Rate"));
  compound_label = new QLabel(tr("Compound"));

  amount_line = new QLineEdit();
  term_y_line = new QLineEdit();
  term_m_line = new QLineEdit();
  rate_line = new QLineEdit();

  main_text = new QTextEdit();

  calculate = new QPushButton(tr("Calculate"));
  calculate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

  annually = new QRadioButton(tr("Annually"));
  monthly = new QRadioButton(tr("Monthly"));
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

  main_layout->addWidget(calculate, 6, 0, 6, 2, Qt::AlignTop);

  main_layout->addWidget(annually, 4, 1);
  main_layout->addWidget(monthly, 5, 1);

}

void CreditCalc::CalcClicked() {
  main_text->clear();

  QString amount = amount_line->text();
  QString year = term_y_line->text();
  QString month = term_m_line->text();
  QString rate = rate_line->text();

  CheckEmptyLines(amount, year, month, rate);

  if (!main_text->text().isEmpty()) return;

  try {
  Controller c(amount.toDouble(), rate->toDouble(),
               year->toDouble * 12 + month->toDouble());
  } catch (...) {
    main_text->setPlainText(QString("Negative value error"));
  }
}

void CreditCalc::CheckEmptyLines(const QString& a, const QString& b,
                                 const QString& c, const QString& d) {
  if (a.isEmpty()) {
    main_text->setPlainText(Qstring("Empty Amount"));
  } else if (b.isEmpty() && c.isEmpty()) {
    main_text->setPlainText(Qstring("Empty Term"));
  } else if (d.isEmpty()) {
    main_text->setPlainText(Qstring("Empty Rate"));
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

  delete annually;
  delete monthly;
}
