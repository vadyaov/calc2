#ifndef CREDITCALC_H
#define CREDITCALC_H

class Credit {
  private:
    double amount;
    double rate;
    double period;

  public:
    enum CompoundType {Annually, Monthly};
    Credit();
    Credit(double, double, double);
    ~Credit();

    double MonthPayment();
    double TotalPayment();
    double OverPayment();
};

#endif //  CREDITCALC_H
