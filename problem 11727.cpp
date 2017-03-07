#include <iostream>
#include <time.h>

#define MAX_DUR 100             //loans at most 100 months long

using namespace std;

class Loan {
    private:
        double loan_value;
        double car_value;
        int duration;           //duration of loan in months
        int repayment;          //amount of each repayment
        int interest_rate;      //interest rate on total value
        
    public:
        void setInitial(double value, int dur, int repay, int interest);
        void repayUpdate(double payment, int dur);
        void depreciateUpdate(double depr_perc, int dur);
        void printStatus(void);
        int  loanLessThanCar(void);
};

void Loan::setInitial(double value, int dur, int repay, int interest) {
    loan_value = value;           
    car_value = value+repay;      //downpayment equal to one repayment
    duration = dur;
    repayment = repay;
    interest_rate = interest;
}

void Loan::repayUpdate(double payment, int dur) {
    loan_value -= payment*dur;
    duration -= dur;
}

void Loan::depreciateUpdate(double depr_perc, int dur) {
    if (dur > 0) { 
        car_value *= dur*(1-depr_perc);
    } else {
        //initial depreciation at month 0
        car_value *= (1-depr_perc);
    }
    duration -= dur;
}

int Loan::loanLessThanCar(void) {
    return loan_value < car_value;
}

void Loan::printStatus(void) {
    cout << "Loan value: " << loan_value << endl;
    cout << "Car value: " << car_value << endl;
    cout << "Duration remaining: " << duration << endl;
    cout << "Repayment amounts: " << repayment << endl;
}

int main(void) {
    int i, j, interest=1, duration, n_deprs, depr_month;
    double value, repayment, depr_perc;
    Loan carLoan;
    
    cin >> duration >> repayment >> value >> n_deprs;
    carLoan.setInitial(value,duration,repayment,1);
    
    //initial depreciation
    cin >> depr_month >> depr_perc;
    for (i=depr_month; i<n_deprs; i++) {
        for (j=0; j<MAX_DUR; j++) {
            carLoan.depreciateUpdate(depr_perc, depr_month);
            carLoan.printStatus();
        }
    }
    
    return 0;
}
