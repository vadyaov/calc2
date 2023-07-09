#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QWidget>

#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>

#include "../controller.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QGridLayout;
class QLabel;
class QTextEdit;
class QPushButton;
class QRadioButton;
QT_END_NAMESPACE

class CreditCalc : public QWidget {
    Q_OBJECT

  public:
      CreditCalc(QWidget* parent = nullptr);
      ~CreditCalc();

  private slots:
    void CalcClicked();

  private:
    void CreateWidgets();
    void AddWidgets();
    void CheckEmptyLines(const QString& a, const QString& b,
                                 const QString& c, const QString& d);

    QGridLayout *main_layout;

    QLabel *amount_label, *term_label, *rate_label, *compound_label;

    QLineEdit *amount_line, *term_y_line, *term_m_line, *rate_line;

    QTextEdit *main_text;

    QPushButton *calculate;

    QRadioButton *annually, *monthly;
};

#endif //  CREDITCALC_H
