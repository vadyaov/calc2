#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QGridLayout;
class QLabel;
class QTextEdit;
class QPushButton;
class QRadioButton;
class QDateEdit;
class QComboBox;
class QHBoxLayout;
QT_END_NAMESPACE

namespace s21 {
class DepositCalc : public QWidget {
    Q_OBJECT

  public:
      DepositCalc(QWidget* parent = nullptr);
      ~DepositCalc();

  private slots:
    void CalcClicked();

  private:
    void CreateWidgets();
    void AddWidgets();
    void SetWidgets();
    void SetComboBoxItems();
    void CheckEmptyLines();

    QGridLayout *main_layout;

    QLabel *amount_label, *term_label, *rate_label, *tax_label, *freq_label,
           *depo_repl_label, *repl_amount_label, *withdrawals_label, *remove_amount_label,
           *capitalization;

    QLineEdit *amount_line, *rate_line, *tax_line, *repl_amount_line, *remove_amount_line;

    QTextEdit *main_text;

    QPushButton *calculate;

    QComboBox *payment_freq_box, *depo_repl_box, *depo_remove_box, *cap_box;

    QDateEdit *first_day, *last_day;

    QHBoxLayout *date_layout;

};
}  // namespace s21

#endif //  DEPOSITCALC_H
