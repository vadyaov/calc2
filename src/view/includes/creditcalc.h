#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QGridLayout;
class QLabel;
class QTextEdit;
class QPushButton;
class QComboBox;
QT_END_NAMESPACE

namespace s21 {
class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void CalcClicked();

 private:
  void CreateWidgets();
  void AddWidgets();
  void SetWidgets();
  void CheckEmptyLines();

  QGridLayout *main_layout;

  QLabel *amount_label, *term_label, *rate_label, *compound_label;

  QLineEdit *amount_line, *term_y_line, *term_m_line, *rate_line;

  QTextEdit *main_text;

  QPushButton *calculate;

  QComboBox *compound_box;
};
}  // namespace s21

#endif  //  CREDITCALC_H
