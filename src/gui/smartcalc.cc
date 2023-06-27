#include <QLineEdit>
#include <QGridLayout>
#include <QRadioButton>
#include <QLabel>

#include "smartcalc.h"
#include "button.h"

SmartCalc::SmartCalc(QWidget* parent) : QWidget(parent) {
  maindisplay = new QLineEdit();
  maindisplay->setReadOnly(true);
  maindisplay->setAlignment(Qt::AlignRight);
  // i can delete the length check and uncommit this line
  /* maindisplay->setMaxLength(255); */
  QFont font = maindisplay->font();
  font.setPointSize(font.pointSize() + 8);
  maindisplay->setFont(font);

  for (int i = 0; i < NumDigitButtons; ++i)
    DigitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));

  Button *bcsp_btn = CreateButton(tr("<--"), SLOT(BscpClicked()));
  Button *ac_btn = CreateButton(tr("AC"), SLOT(AcClicked()));
  Button *x_btn = CreateButton(tr("X"), SLOT(XClicked()));
  Button *point_btn = CreateButton(tr("."), SLOT(PointClicked()));
  Button *lbracket_btn = CreateButton(tr("("), SLOT(LBracketClicked()));
  Button *rbracket_btn = CreateButton(tr(")"), SLOT(RBracketClicked()));
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

  QLineEdit *x_display = new QLineEdit();
  x_display->setAlignment(Qt::AlignCenter);
  x_display->setPlaceholderText(QString("x"));
  x_display->setMaximumWidth(80);
  x_display->setMaximumHeight(60);
  QLineEdit *xmin_display = new QLineEdit();
  xmin_display->setPlaceholderText(QString("X min"));
  QLineEdit *xmax_display = new QLineEdit();
  xmax_display->setPlaceholderText(QString("X max"));
  QLineEdit *step_display = new QLineEdit();
  step_display->setPlaceholderText(QString("step"));
  QLineEdit *ymin_display = new QLineEdit();
  ymin_display->setPlaceholderText(QString("Y min"));
  QLineEdit *ymax_display = new QLineEdit();
  ymax_display->setPlaceholderText(QString("Y max"));

  /* QLabel *x_label = new QLabel(tr("x:")); */
  /* x_label->setAlignment(Qt::AlignCenter | Qt::AlignRight); */
  /* QLabel *xmin_label = new QLabel(tr("from x:")); */
  /* QLabel *xmax_label = new QLabel(tr("to x:")); */
  /* QLabel *step_label = new QLabel(tr("X Step")); */
  /* QLabel *y_min_label = new QLabel(tr("from y:")); */
  /* QLabel *y_max_label = new QLabel(tr("to y:")); */

  QRadioButton *graph_btn = new QRadioButton("plot", this);
  myplot = new QCustomPlot();

  QGridLayout *main_layout = new QGridLayout;
  /* main_layout->setSizeConstraint(QLayout::SetFixedSize); */

  InitGraph(myplot);

  /* x_display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); */
  /* x_display->setMaximumWidth(50); */
  xmin_display->setMaximumWidth(60);
  xmax_display->setMaximumWidth(60);
  step_display->setMaximumWidth(60);
  ymin_display->setMaximumWidth(60);
  ymax_display->setMaximumWidth(60);

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
  main_layout->addWidget(x_btn, 1, 0);
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
  main_layout->addWidget(x_display, 1, 1);
  main_layout->addWidget(graph_btn, 5, 0);
  /* main_layout->addWidget(x_label, 5, 1); */
  #if defined __APPLE__ && defined __MACH__
  main_layout->addWidget(myplot, 6, 0, 30, 7);
  #else
  main_layout->addWidget(myplot, 6, 0, 50, 7);
  #endif

  /* main_layout->addWidget(xmin_label, 6, 6); */
  /* main_layout->addWidget(xmax_label, 8, 6); */
  /* main_layout->addWidget(step_label, 10, 6); */
  #if defined __APPLE__ && defined __MACH__
  /* main_layout->addWidget(xmin_display, 58, 0); */
  /* main_layout->addWidget(xmax_display, 58, 1); */
  /* main_layout->addWidget(step_display, 58, 3); */
  #else
  main_layout->addWidget(xmin_display, 58, 0);
  main_layout->addWidget(xmax_display, 58, 1);
  main_layout->addWidget(step_display, 58, 3);
  #endif
  /* main_layout->addWidget(y_min_label, 14, 6); */
  main_layout->addWidget(ymin_display, 58, 5);
  /* main_layout->addWidget(y_max_label, 16, 6); */
  main_layout->addWidget(ymax_display, 58, 6);

  setLayout(main_layout);

  setWindowTitle("SmartCalc");

}

/* SmartCalc::~SmartCalc() { */
  /* delete maindisplay; */
  /* for (int i = 0; i < NumDigitButtons; ++i) */
  /*   delete DigitButtons[i]; */

  /* delete bcsp_btn; */
  /* delete ac_btn; */
  /* delete x_btn; */
  /* delete point_btn; */
  /* delete lbracket_btn; */
  /* delete rbracket_btn; */
  /* delete div_btn; */
  /* delete mult_btn; */
  /* delete minus_btn; */
  /* delete plus_btn; */
  /* delete mod_btn; */
  /* delete pow_btn; */
  /* delete equal_btn; */
  /* delete sin_btn; */
  /* delete cos_btn; */
  /* delete tan_btn; */
  /* delete asin_btn; */
  /* delete acos_btn; */
  /* delete atan_btn; */
  /* delete ln_btn; */
  /* delete log_btn; */
  /* delete sqrt_btn; */

  /* delete main_layout; */
/* } */

void SmartCalc::DigitClicked() {
  Button *clicked_button = qobject_cast<Button*>(sender());
  int digit_value = clicked_button->text().toInt();
  if (maindisplay->text() == "0" && digit_value == 0.0)
    return;

  maindisplay->setText(maindisplay->text() + QString::number(digit_value));
}

void SmartCalc::BscpClicked() {
  QString text = maindisplay->text();
  text.chop(1);
  maindisplay->setText(text);
}

void SmartCalc::AcClicked() {
  maindisplay->clear();
}

void SmartCalc::XClicked() {
  maindisplay->setText(maindisplay->text() + QString('x'));
}

void SmartCalc::PointClicked() {
  maindisplay->setText(maindisplay->text() + QString('.'));
}

void SmartCalc::LBracketClicked() {
  maindisplay->setText(maindisplay->text() + QString('('));
}

void SmartCalc::RBracketClicked() {
  maindisplay->setText(maindisplay->text() + QString(')'));
}

void SmartCalc::DivClicked() {
  maindisplay->setText(maindisplay->text() + QString('/'));
}

void SmartCalc::MultClicked() {
  maindisplay->setText(maindisplay->text() + QString('*'));
}

void SmartCalc::MinusClicked() {
  maindisplay->setText(maindisplay->text() + QString('-'));
}

void SmartCalc::PlusClicked() {
  maindisplay->setText(maindisplay->text() + QString('+'));
}

void SmartCalc::ModClicked() {
  maindisplay->setText(maindisplay->text() + QString("mod"));
}

void SmartCalc::PowClicked() {
  maindisplay->setText(maindisplay->text() + QString('^'));
}

void SmartCalc::EqualClicked() {
}

void SmartCalc::SinClicked() {
  maindisplay->setText(maindisplay->text() + QString("sin("));
}

void SmartCalc::CosClicked() {
  maindisplay->setText(maindisplay->text() + QString("cos("));
}

void SmartCalc::TanClicked() {
  maindisplay->setText(maindisplay->text() + QString("tan("));
}

void SmartCalc::AsinClicked() {
  maindisplay->setText(maindisplay->text() + QString("asin("));
}

void SmartCalc::AcosClicked() {
  maindisplay->setText(maindisplay->text() + QString("acos("));
}

void SmartCalc::AtanClicked() {
  maindisplay->setText(maindisplay->text() + QString("atan("));
}

void SmartCalc::LnClicked() {
  maindisplay->setText(maindisplay->text() + QString("ln("));
}

void SmartCalc::LogClicked() {
  maindisplay->setText(maindisplay->text() + QString("log("));
}

void SmartCalc::SqrtClicked() {
  maindisplay->setText(maindisplay->text() + QString("sqrt("));
}

Button* SmartCalc::CreateButton(const QString &text, const char *member) {
  Button *button = new Button(text);
  connect(button, SIGNAL(clicked()), this, member);
  return button;
}

void SmartCalc::InitGraph(QCustomPlot *plot) {
  plot->addGraph();
  plot->graph(0)->setPen(QPen(Qt::blue));
  plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
  plot->xAxis2->setVisible(true);
  plot->xAxis2->setTickLabels(false);
  plot->yAxis2->setVisible(true);
  plot->yAxis2->setTickLabels(false);
  plot->xAxis->setLabel("x");
  plot->yAxis->setLabel("y");
  plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                        QCP::iSelectPlottables);
}
