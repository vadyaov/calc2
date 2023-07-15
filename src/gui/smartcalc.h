#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>

#include "qcustomplot.h"
#include "../controller.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class GridLayout;
class QRadioButton;
class QLabel;
QT_END_NAMESPACE
class Button;

class SmartCalc : public QWidget {
    Q_OBJECT

  public:
      SmartCalc(QWidget* parent = nullptr);
      ~SmartCalc();

  private slots:
    void DigitClicked();
    void FunctionClicked();
    void OtherClicked();

    void BscpClicked();
    void AcClicked();
    void EqualClicked();

  private:
    Button *CreateButton(const QString &text, const char *member);
    enum { NumDigitButtons = 10 };

    void CreateWidgets();
    void AddWidgets();
    void TuneWidgets();
    void InitGraph(QCustomPlot *plot);
    void PrintPlot(const Controller&);

    QGridLayout *main_layout;

    Button *DigitButtons[NumDigitButtons];

    Button *bcsp_btn, *ac_btn, *x_btn, *point_btn, *lbracket_btn, *rbracket_btn,
           *div_btn, *mult_btn, *minus_btn, *plus_btn, *mod_btn, *pow_btn,
           *equal_btn, *sin_btn, *cos_btn, *tan_btn, *asin_btn, *acos_btn,
           *atan_btn, *ln_btn, *log_btn, *sqrt_btn;

    QLineEdit *main_display, *x_display, *xmin_display, *xmax_display,
              *step_display, *ymin_display, *ymax_display;

    QRadioButton *graph_btn;

    QCustomPlot *myplot;

};

#endif //  SMARTCALC_H
