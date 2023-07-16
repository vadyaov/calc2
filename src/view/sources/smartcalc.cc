#include "../includes/smartcalc.h"
#include "../includes/button.h"

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
}

void SmartCalc::CreateWidgets() {
  main_display = new QLineEdit;
  x_display = new QLineEdit;
  xmin_display = new QLineEdit(tr("-10"));
  xmax_display = new QLineEdit(tr("+10"));
  step_display = new QLineEdit(tr("0.1"));
  ymin_display = new QLineEdit(tr("-10"));
  ymax_display = new QLineEdit(tr("+10"));

  graph_btn = new QRadioButton("plot", this);
  myplot = new QCustomPlot;

  main_layout = new QGridLayout;

  for (int i = 0; i < NumDigitButtons; ++i)
    DigitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));

  
  bcsp_btn = CreateButton(tr("<--"), SLOT(BscpClicked()));
  ac_btn = CreateButton(tr("AC"), SLOT(AcClicked()));
  equal_btn = CreateButton(tr("="), SLOT(EqualClicked()));

  x_btn = CreateButton(tr("X"), SLOT(OtherClicked()));
  point_btn = CreateButton(tr("."), SLOT(OtherClicked()));
  lbracket_btn = CreateButton(tr("("), SLOT(OtherClicked()));
  rbracket_btn = CreateButton(tr(")"), SLOT(OtherClicked()));
  div_btn = CreateButton(tr("\303\267"), SLOT(OtherClicked()));
  mult_btn = CreateButton(tr("\303\227"), SLOT(OtherClicked()));
  minus_btn = CreateButton(tr("-"), SLOT(OtherClicked()));
  plus_btn = CreateButton(tr("+"), SLOT(OtherClicked()));
  mod_btn = CreateButton(tr("mod"), SLOT(OtherClicked()));
  pow_btn = CreateButton(tr("^"), SLOT(OtherClicked()));

  sin_btn = CreateButton(tr("sin"), SLOT(FunctionClicked()));
  cos_btn = CreateButton(tr("cos"), SLOT(FunctionClicked()));
  tan_btn = CreateButton(tr("tan"), SLOT(FunctionClicked()));
  asin_btn = CreateButton(tr("asin"), SLOT(FunctionClicked()));
  acos_btn = CreateButton(tr("acos"), SLOT(FunctionClicked()));
  atan_btn = CreateButton(tr("atan"), SLOT(FunctionClicked()));
  ln_btn = CreateButton(tr("ln"), SLOT(FunctionClicked()));
  log_btn = CreateButton(tr("log"), SLOT(FunctionClicked()));
  sqrt_btn = CreateButton(tr("sqrt"), SLOT(FunctionClicked()));
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
  main_layout->addWidget(xmin_display, 58, 0); // change in school
  main_layout->addWidget(xmax_display, 58, 1);
  main_layout->addWidget(step_display, 58, 3);
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

  QFont main_font = main_display->font();
  main_font.setPointSize(main_font.pointSize() + 8);
  main_display->setFont(main_font);

  xmin_display->setMaximumWidth(60);
  ymin_display->setMaximumWidth(60);
  xmax_display->setMaximumWidth(60);
  ymax_display->setMaximumWidth(60);
  step_display->setMaximumWidth(60);
  x_display->setMaximumWidth(80);
  x_display->setMaximumHeight(60);

  xmin_display->setAlignment(Qt::AlignCenter);
  ymin_display->setAlignment(Qt::AlignCenter);
  xmax_display->setAlignment(Qt::AlignCenter);
  ymax_display->setAlignment(Qt::AlignCenter);
  step_display->setAlignment(Qt::AlignCenter);
  x_display->setAlignment(Qt::AlignCenter);

  xmin_display->setPlaceholderText(QString("X min"));
  xmax_display->setPlaceholderText(QString("X max"));
  ymin_display->setPlaceholderText(QString("Y min"));
  ymax_display->setPlaceholderText(QString("Y max"));
  step_display->setPlaceholderText(QString("step"));
  x_display->setPlaceholderText(QString("x"));

  x_display->setStyleSheet("color: grey; background-color: lightgrey;");
  xmin_display->setStyleSheet("color: blue; background-color: lightgrey;");
  xmax_display->setStyleSheet("color: blue; background-color: lightgrey;");
  ymin_display->setStyleSheet("color: green; background-color: lightgrey;");
  ymax_display->setStyleSheet("color: green; background-color: lightgrey;");
  equal_btn->setStyleSheet("color: black; background-color: lightBlue;");
  point_btn->setStyleSheet("color: black; background-color: grey;");
  graph_btn->setStyleSheet("color: purple; background-color: white;");
  for (auto ptr : DigitButtons)
    ptr->setStyleSheet("color: black; background-color: grey;");
  bcsp_btn->setIcon(style()->standardIcon(QStyle::SP_ArrowBack));

  QFont x_font = x_display->font();
  x_font.setPointSize(x_font.pointSize() + 2);
  x_display->setFont(x_font);

  QFont f = plus_btn->font();
  f.setPointSize(f.pointSize() + 4);

  plus_btn->setFont(f);
  minus_btn->setFont(f);
  div_btn->setFont(f);
  mult_btn->setFont(f);
  ac_btn->setFont(f);
  point_btn->setFont(f);
  lbracket_btn->setFont(f);
  rbracket_btn->setFont(f);
  mod_btn->setFont(f);
  pow_btn->setFont(f);
  equal_btn->setFont(f);
  sin_btn->setFont(f);
  cos_btn->setFont(f);
  tan_btn->setFont(f);
  asin_btn->setFont(f);
  acos_btn->setFont(f);
  atan_btn->setFont(f);
  ln_btn->setFont(f);
  log_btn->setFont(f);
  sqrt_btn->setFont(f);
  graph_btn->setFont(f);
}

void SmartCalc::DigitClicked() {
  Button *clicked_button = qobject_cast<Button*>(sender());
  int digit_value = clicked_button->text().toInt();
  if (main_display->text() == "0" && digit_value == 0.0)
    return;

  main_display->setText(main_display->text() + QString::number(digit_value));
}

void SmartCalc::FunctionClicked() {
  Button *clicked = qobject_cast<Button *>(sender());
  QString btn_text = clicked->text();
  main_display->setText(main_display->text() + btn_text + QString("("));
}

void SmartCalc::OtherClicked() {
  Button *clicked = qobject_cast<Button *>(sender());
  QString btn_text = clicked->text();
  main_display->setText(main_display->text() + btn_text);
}


void SmartCalc::BscpClicked() {
  QString text = main_display->text();
  text.chop(1);
  main_display->setText(text);
}

void SmartCalc::AcClicked() {
  main_display->clear();
}

void SmartCalc::EqualClicked() {
  double x = x_display->text().toDouble();
  try{

    Controller c(main_display->text().toStdString());
    if (graph_btn->isChecked())
      PrintPlot(c);
    else
      main_display->setText(QString::number(c.Calculate(x)));

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
         y_start = y1.toDouble(), y_end = y2.toDouble();

  if (!(x_end > x_start) || !(y_end > y_start)) {
    main_display->setText(QString("Incorrect range"));
    return;
  }

  double step = step_display->text().toDouble();

  if (step < EPS) {
    main_display->setText(QString("Incorrect step"));
    return;
  }

  int dots = (x_end - x_start) / step + 1;
  std::set <int> to_skip;

  int number = 0;
  for (double x = x_start; x <= x_end; x += step, ++number) {
    double res = c.Calculate(x);
    if ((res < YMAX && res - y_end > EPS) || (res > YMIN && y_start - res > EPS)) {
      to_skip.insert(number);
      --dots;
    }
  }

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
    ++i;
  }

  myplot->graph(0)->setData(x, y);
  myplot->xAxis->rescale();
  myplot->replot();

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
