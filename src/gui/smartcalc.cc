#include <QLineEdit>
#include <QGridLayout>

#include "smartcalc.h"
#include "button.h"

SmartCalc::SmartCalc(QWidget* parent) : QWidget(parent) {
  maindisplay = new QLineEdit("0");
  QFont font = maindisplay->font();
  font.setPointSize(font.pointSize() + 8);
  maindisplay->setFont(font);

  for (int i = 0; i < NumDigitButtons; ++i)
    DigitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));

  Button *bcsp_btn = CreateButton(tr("<--"), SLOT(BscpClicked()));
  Button *ac_btn = CreateButton(tr("AC"), SLOT(AcClicked()));
  Button *x_btn = CreateButton(tr("X"), SLOT(XClicked()));
  Button *point_btn = CreateButton(tr("."), SLOT(PointClicked()));
  Button *lbracket_btn = CreateButton(tr("("), SLOT(LbracketClicked()));
  Button *rbracket_btn = CreateButton(tr(")"), SLOT(RbracketClicked()));
  Button *div_btn = CreateButton(tr("\303\267"), SLOT(DivClicked()));
  Button *mult_btn = CreateButton(tr("\303\227"), SLOT(MultClicked()));
  Button *minus_btn = CreateButton(tr("-"), SLOT(MinusClicked()));
  Button *plus_btn = CreateButton(tr("+"), SLOT(PlusClicked()));
  Button *mod_btn = CreateButton(tr("mod"), SLOT(ModClicked()));
  Button *pow_btn = CreateButton(tr("^"), SLOT(PowClicked()));
  Button *equal_btn = CreateButton(tr("="), SLOT(EqualClicked()));
  Button *sin_btn = CreateButton(tr("sin"), SLOT(SinClicked()));
  Button *cos_btn = CreateButton(tr("cos"), SLOT(CosClicked()));
  Button *tan_btn = CreateButton(tr("tan"), SLOT(TanClicked()));
  Button *asin_btn = CreateButton(tr("asin"), SLOT(AsinClicked()));
  Button *acos_btn = CreateButton(tr("acos"), SLOT(AcosClicked()));
  Button *atan_btn = CreateButton(tr("atan"), SLOT(AtanClicked()));
  Button *ln_btn = CreateButton(tr("ln"), SLOT(LnClicked()));
  Button *log_btn = CreateButton(tr("log"), SLOT(LogClicked()));
  Button *sqrt_btn = CreateButton(tr("sqrt"), SLOT(SqrtClicked()));

  QGridLayout *main_layout = new QGridLayout;
  main_layout->setSizeConstraint(QLayout::SetFixedSize);

  main_layout->addWidget(DigitButtons[0], 5, 3);
  main_layout->addWidget(DigitButtons[1], 4, 3);
  main_layout->addWidget(DigitButtons[2], 4, 4);
  main_layout->addWidget(DigitButtons[3], 4, 5);
  main_layout->addWidget(DigitButtons[4], 3, 3);
  main_layout->addWidget(DigitButtons[5], 3, 4);
  main_layout->addWidget(DigitButtons[6], 3, 5);
  main_layout->addWidget(DigitButtons[7], 2, 3);
  main_layout->addWidget(DigitButtons[8], 2, 4);
  main_layout->addWidget(DigitButtons[9], 2, 5);
  main_layout->addWidget(bcsp_btn, 0, 6);
  main_layout->addWidget(ac_btn, 1, 6);
  main_layout->addWidget(x_btn, 1, 1);
  main_layout->addWidget(point_btn, 5, 4);
  main_layout->addWidget(lbracket_btn, 1, 3);
  main_layout->addWidget(rbracket_btn, 1, 4);
  main_layout->addWidget(div_btn, 2, 6);
  main_layout->addWidget(mult_btn, 3, 6);
  main_layout->addWidget(minus_btn, 4, 6);
  main_layout->addWidget(plus_btn, 5, 6);
  main_layout->addWidget(mod_btn, 1, 5);
  main_layout->addWidget(pow_btn, 1, 2);
  main_layout->addWidget(equal_btn, 5, 5);
  main_layout->addWidget(sin_btn, 2, 1);
  main_layout->addWidget(cos_btn, 3, 1);
  main_layout->addWidget(tan_btn, 4, 1);
  main_layout->addWidget(asin_btn, 2, 0);
  main_layout->addWidget(acos_btn, 3, 0);
  main_layout->addWidget(atan_btn, 4, 0);
  main_layout->addWidget(ln_btn, 2, 2);
  main_layout->addWidget(log_btn, 3, 2);
  main_layout->addWidget(sqrt_btn, 4, 2);
  main_layout->addWidget(maindisplay, 0, 0, 1, 6);

  setLayout(main_layout);

  setWindowTitle("SmartCalc");

}

SmartCalc::~SmartCalc() {
  delete maindisplay;
}

void SmartCalc::DigitClicked() {
  Button *clicked_button = qobject_cast<Button*>(sender());
  int digit_value = clicked_button->text().toInt();
  if (maindisplay->text() == "0" && digit_value == 0.0)
    return;

  maindisplay->setText(maindisplay->text() + QString::number(digit_value));
}

Button* SmartCalc::CreateButton(const QString &text, const char *member) {
  Button *button = new Button(text);
  connect(button, SIGNAL(clicked()), this, member);
  return button;
}
