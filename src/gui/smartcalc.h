#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>

#include "qcustomplot.h"

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

    void CreateWidgets();
    void AddWidgets();
    void TuneWidgets();
    void InitGraph(QCustomPlot *plot);
    void PrintPlot(const Controller&);
    /* int CountDots(double, double, double, double); */

    /* QTabWidget *calc_widget; */
    /* QFrame *frame_1, *frame_2, *frame_3; */
    QGridLayout *main_layout; //, *credit_layout, *deposit_layout;

  /* -------------------------MainCalc Widgets---------------------------*/

    Button *DigitButtons[NumDigitButtons];

    Button *bcsp_btn;
    Button *ac_btn;
    Button *x_btn;
    Button *point_btn;
    Button *lbracket_btn;
    Button *rbracket_btn;
    Button *div_btn;
    Button *mult_btn;
    Button *minus_btn;
    Button *plus_btn;
    Button *mod_btn;
    Button *pow_btn;
    Button *equal_btn;
    Button *sin_btn;
    Button *cos_btn;
    Button *tan_btn;
    Button *asin_btn;
    Button *acos_btn;
    Button *atan_btn;
    Button *ln_btn;
    Button *log_btn;
    Button *sqrt_btn;

    QLineEdit *main_display, *x_display, *xmin_display, *xmax_display,
              *step_display, *ymin_display, *ymax_display;

    QRadioButton *graph_btn;

    QCustomPlot *myplot;

};

#endif //  SMARTCALC_H
