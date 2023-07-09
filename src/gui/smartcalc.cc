#include "smartcalc.h"
#include "button.h"

#include <iostream>
#include <set>
#include <limits>

constexpr double EPS = 1e-7;
constexpr double YMAX = 1e6;
constexpr double YMIN = -1e6;

SmartCalc::SmartCalc(QWidget* parent) : QWidget(parent) {
  CreateWidgets();
  AddWidgets();
  InitGraph(myplot);
  TuneWidgets();

  setLayout(main_layout);
  setWindowTitle("SmartCalc");
}

void SmartCalc::CreateWidgets() {
  main_display = new QLineEdit();
  x_display = new QLineEdit();
  xmin_display = new QLineEdit(QString("-10"));
  xmax_display = new QLineEdit(QString("+10"));
  step_display = new QLineEdit();
  ymin_display = new QLineEdit(QString("-10"));
  ymax_display = new QLineEdit(QString("+10"));

  graph_btn = new QRadioButton("plot", this);
  myplot = new QCustomPlot();

  main_layout = new QGridLayout;

  for (int i = 0; i < NumDigitButtons; ++i)
    DigitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));

  bcsp_btn = CreateButton(tr("<--"), SLOT(BscpClicked()));
  ac_btn = CreateButton(tr("AC"), SLOT(AcClicked()));
  x_btn = CreateButton(tr("X"), SLOT(XClicked()));
  point_btn = CreateButton(tr("."), SLOT(PointClicked()));
  lbracket_btn = CreateButton(tr("("), SLOT(LBracketClicked()));
  rbracket_btn = CreateButton(tr(")"), SLOT(RBracketClicked()));
  div_btn = CreateButton(tr("\303\267"), SLOT(DivClicked()));
  mult_btn = CreateButton(tr("\303\227"), SLOT(MultClicked()));
  minus_btn = CreateButton(tr("-"), SLOT(MinusClicked()));
  plus_btn = CreateButton(tr("+"), SLOT(PlusClicked()));
  mod_btn = CreateButton(tr("mod"), SLOT(ModClicked()));
  pow_btn = CreateButton(tr("^"), SLOT(PowClicked()));
  equal_btn = CreateButton(tr("="), SLOT(EqualClicked()));
  sin_btn = CreateButton(tr("sin"), SLOT(SinClicked()));
  cos_btn = CreateButton(tr("cos"), SLOT(CosClicked()));
  tan_btn = CreateButton(tr("tan"), SLOT(TanClicked()));
  asin_btn = CreateButton(tr("asin"), SLOT(AsinClicked()));
  acos_btn = CreateButton(tr("acos"), SLOT(AcosClicked()));
  atan_btn = CreateButton(tr("atan"), SLOT(AtanClicked()));
  ln_btn = CreateButton(tr("ln"), SLOT(LnClicked()));
  log_btn = CreateButton(tr("log"), SLOT(LogClicked()));
  sqrt_btn = CreateButton(tr("sqrt"), SLOT(SqrtClicked()));
}

void SmartCalc::AddWidgets() {
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

  main_layout->addWidget(main_display, 0, 0, 1, 6);
  main_layout->addWidget(x_display, 1, 1);
  main_layout->addWidget(graph_btn, 5, 0);
  #if defined __APPLE__ && defined __MACH__
  main_layout->addWidget(myplot, 6, 0, 30, 7);
  #else
  main_layout->addWidget(myplot, 6, 0, 50, 7);
  #endif

  #if defined __APPLE__ && defined __MACH__
  /* main_layout->addWidget(xmin_display, 58, 0); */
  /* main_layout->addWidget(xmax_display, 58, 1); */
  /* main_layout->addWidget(step_display, 58, 3); */
  #else
  main_layout->addWidget(xmin_display, 58, 0);
  main_layout->addWidget(xmax_display, 58, 1);
  main_layout->addWidget(step_display, 58, 3);
  #endif
  main_layout->addWidget(ymin_display, 58, 5);
  main_layout->addWidget(ymax_display, 58, 6);

}

void SmartCalc::TuneWidgets() {
  main_display->setReadOnly(true);
  main_display->setAlignment(Qt::AlignRight);
  main_display->setMaxLength(255);

  QFont font = main_display->font();
  font.setPointSize(font.pointSize() + 8);
  main_display->setFont(font);

  x_display->setAlignment(Qt::AlignCenter);
  x_display->setPlaceholderText(QString("x"));
  x_display->setMaximumWidth(80);
  x_display->setMaximumHeight(60);

  xmin_display->setPlaceholderText(QString("X min"));
  xmin_display->setMaximumWidth(60);

  xmax_display->setPlaceholderText(QString("X max"));
  xmax_display->setMaximumWidth(60);

  step_display->setPlaceholderText(QString("step"));
  step_display->setMaximumWidth(60);

  ymin_display->setPlaceholderText(QString("Y min"));
  ymin_display->setMaximumWidth(60);

  ymax_display->setPlaceholderText(QString("Y max"));
  ymax_display->setMaximumWidth(60);
}

void SmartCalc::DigitClicked() {
  Button *clicked_button = qobject_cast<Button*>(sender());
  int digit_value = clicked_button->text().toInt();
  if (main_display->text() == "0" && digit_value == 0.0)
    return;

  main_display->setText(main_display->text() + QString::number(digit_value));
}

void SmartCalc::BscpClicked() {
  QString text = main_display->text();
  text.chop(1);
  main_display->setText(text);
}

void SmartCalc::AcClicked() {
  main_display->clear();
}

void SmartCalc::XClicked() {
  main_display->setText(main_display->text() + QString('x'));
}

void SmartCalc::PointClicked() {
  main_display->setText(main_display->text() + QString('.'));
}

void SmartCalc::LBracketClicked() {
  main_display->setText(main_display->text() + QString('('));
}

void SmartCalc::RBracketClicked() {
  main_display->setText(main_display->text() + QString(')'));
}

void SmartCalc::DivClicked() {
  main_display->setText(main_display->text() + QString('/'));
}

void SmartCalc::MultClicked() {
  main_display->setText(main_display->text() + QString('*'));
}

void SmartCalc::MinusClicked() {
  main_display->setText(main_display->text() + QString('-'));
}

void SmartCalc::PlusClicked() {
  main_display->setText(main_display->text() + QString('+'));
}

void SmartCalc::ModClicked() {
  main_display->setText(main_display->text() + QString("mod"));
}

void SmartCalc::PowClicked() {
  main_display->setText(main_display->text() + QString('^'));
}

void SmartCalc::EqualClicked() {
  double x = x_display->text().toDouble();
  try{
    Controller c(main_display->text().toStdString());
    if (graph_btn->isChecked()) {
      PrintPlot(c);
    } else {
      main_display->setText(QString::number(c.Calculate(x)));
    }
  } catch (...) {
    main_display->setText(QString("Incorrect expression"));
  }
}

void SmartCalc::PrintPlot(const Controller& c) {
  QString x1 = xmin_display->text(), x2 = xmax_display->text(),
          y1 = ymin_display->text(), y2 = ymax_display->text();
  if (x1.isEmpty() || x2.isEmpty() || y1.isEmpty() || y2.isEmpty()) {
    main_display->setText(QString("Unknown range"));
    return;
  }
  
  double x_start = x1.toDouble(), x_end = x2.toDouble(),
         y_start = y1.toDouble(), y_end = y2.toDouble(),
         step = step_display->text().isEmpty() ? 0.1 : step_display->text().toDouble();

  if (!(x_end > x_start) || !(y_end > y_start)) {
    main_display->setText(QString("Incorrect range"));
    return;
  }

  int dots = (x_end - x_start) / step + 1;
  std::set <int> to_skip;

  int number = 0;
  for (double x = x_start; x <= x_end; x += step, ++number) {
    double res = c.Calculate(x);
    /* std::cout << res << std::endl; */
    if ((res < YMAX && res - y_end > EPS) || (res > YMIN && y_start - res > EPS)) {
      to_skip.insert(number);
      --dots;
    }
  }

  /* std::cout << "to skip: "; */
  /* for (auto i : to_skip) */
  /*   std::cout << i; */
  /* std::cout << std::endl; */

  /* std::cout << "dots = " << dots << std::endl; */

  QVector<double> x(dots), y(dots);
  for (int i = 0, k = 0; i < dots; ++k) {
    if (to_skip.find(k) != to_skip.end()) {
      x_start += step;
      continue;
    }
    x[i] = x_start;
    if (x[i] < EPS && x[i] > -EPS) x[i] = 0.0;
    y[i] = c.Calculate(x[i]);
    if (y[i] > YMAX) y[i] = std::numeric_limits<double>::infinity();
    if (y[i] < YMIN) y[i] = -std::numeric_limits<double>::infinity();
    x_start += step;
    /* std::cout << x[i] << ' ' << y[i] << std::endl; */
    ++i;
  }

  myplot->graph(0)->setData(x, y);
  myplot->xAxis->rescale();
  myplot->replot();

}

void SmartCalc::SinClicked() {
  main_display->setText(main_display->text() + QString("sin("));
}

void SmartCalc::CosClicked() {
  main_display->setText(main_display->text() + QString("cos("));
}

void SmartCalc::TanClicked() {
  main_display->setText(main_display->text() + QString("tan("));
}

void SmartCalc::AsinClicked() {
  main_display->setText(main_display->text() + QString("asin("));
}

void SmartCalc::AcosClicked() {
  main_display->setText(main_display->text() + QString("acos("));
}

void SmartCalc::AtanClicked() {
  main_display->setText(main_display->text() + QString("atan("));
}

void SmartCalc::LnClicked() {
  main_display->setText(main_display->text() + QString("ln("));
}

void SmartCalc::LogClicked() {
  main_display->setText(main_display->text() + QString("log("));
}

void SmartCalc::SqrtClicked() {
  main_display->setText(main_display->text() + QString("sqrt("));
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

SmartCalc::~SmartCalc() {
  delete main_display, xmin_display, xmax_display, step_display,
              ymin_display, ymax_display;
  delete x_display;
  for (int i = 0; i < NumDigitButtons; ++i)
    delete DigitButtons[i];

  delete myplot;

  delete graph_btn;

  delete bcsp_btn;
  delete ac_btn;
  delete x_btn;
  delete point_btn;
  delete lbracket_btn;
  delete rbracket_btn;
  delete div_btn;
  delete mult_btn;
  delete minus_btn;
  delete plus_btn;
  delete mod_btn;
  delete pow_btn;
  delete equal_btn;
  delete sin_btn;
  delete cos_btn;
  delete tan_btn;
  delete asin_btn;
  delete acos_btn;
  delete atan_btn;
  delete ln_btn;
  delete log_btn;
  delete sqrt_btn;

  delete main_layout;
}
