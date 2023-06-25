#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE
class Button;

class SmartCalc : public QWidget {
    Q_OBJECT

  public:
      SmartCalc(QWidget* parent = nullptr);
      ~SmartCalc();

  private slots:
    void DigitClicked();

  private:
    Button *CreateButton(const QString &text, const char *member);
    enum { NumDigitButtons = 10 };

    /* QTabWidget *calc_widget; */
    /* QFrame *frame_1, *frame_2, *frame_3; */
    /* QGridLayout *main_layout; //, *credit_layout, *deposit_layout; */

  /* -------------------------MainCalc Widgets---------------------------*/

    Button *DigitButtons[NumDigitButtons];

    QLineEdit *maindisplay;

};

#endif //  SMARTCALC_H
