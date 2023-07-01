#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>

#include "qcustomplot.h"
#include "../controller.h"

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
    void BscpClicked();
    void AcClicked();
    void XClicked();
    void PointClicked();
    void LBracketClicked();
    void RBracketClicked();
    void DivClicked();
    void MultClicked();
    void MinusClicked();
    void PlusClicked();
    void ModClicked();
    void PowClicked();
    void EqualClicked();
    void SinClicked();
    void CosClicked();
    void TanClicked();
    void AsinClicked();
    void AcosClicked();
    void AtanClicked();
    void LnClicked();
    void LogClicked();
    void SqrtClicked();

  private:
    Button *CreateButton(const QString &text, const char *member);
    enum { NumDigitButtons = 10 };
    void InitGraph(QCustomPlot *plot);
    void PrintPlot(const Controller&);
    /* int CountDots(double, double, double, double); */

    /* QTabWidget *calc_widget; */
    /* QFrame *frame_1, *frame_2, *frame_3; */
    /* QGridLayout *main_layout; //, *credit_layout, *deposit_layout; */

  /* -------------------------MainCalc Widgets---------------------------*/

    Button *DigitButtons[NumDigitButtons];

    QLineEdit *main_display, *x_display, *xmin_display, *xmax_display, *step_display,
              *ymin_display, *ymax_display;

    QRadioButton *graph_btn;

    QCustomPlot *myplot;

};

#endif //  SMARTCALC_H
