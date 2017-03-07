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
        void updateRepayment(double payment, int dur);
        void updateDepreciation(double depr_perc, int dur);
        void updateDuration(int dur);
        void printStatus(void);
        int  loanLessThanCar(void);
};

//set Initial terms of the loan
void Loan::setInitial(double value, int dur, int repay, int interest) {
    loan_value = value;           
    car_value = value+repay;      //downpayment equal to one repayment
    duration = dur;
    repayment = repay;
    interest_rate = interest;
}

//update loan value after repayments
void Loan::updateRepayment(double payment, int dur) {
    loan_value -= payment*dur;
}

//update car value after depreciation
void Loan::updateDepreciation(double depr_perc, int dur) {
    if (dur > 0) { 
        car_value *= dur*(1-depr_perc);
    } else {
        //initial depreciation at month 0
        car_value *= (1-depr_perc);
    }
}

//update duration remaining on loan
void Loan::updateDuration(int dur) {
    duration -= dur;
}

//check if loan value is less than car value
int Loan::loanLessThanCar(void) {
    return loan_value < car_value;
}

//print outstanding values of loan
void Loan::printStatus(void) {
    cout << "Loan value: " << loan_value << endl;
    cout << "Car value: " << car_value << endl;
    cout << "Duration remaining: " << duration << endl;
    cout << "Repayment amounts: " << repayment << endl;
    cout << endl;
}

int main(void) {
    int i, j, interest=1, duration, n_deprs, curr_month, depr_month;
    double value, repayment, depr_perc;
    Loan carLoan;
    
    cin >> duration >> repayment >> value >> n_deprs;
    carLoan.setInitial(value,duration,repayment,1);
    
    //initial depreciation
    cin >> depr_month >> depr_perc;
    curr_month=0;
    for (i=1; i<n_deprs; i++) {
        cin >> depr_month;
        while (curr_month < depr_month) {
            //increment through repay/decr by one month
            carLoan.updateDepreciation(depr_perc, 1);
            carLoan.updateRepayment(repayment, 1);
            carLoan.updateDuration(1);
            carLoan.printStatus();
            if (carLoan.loanLessThanCar()) {
                cout << curr_month << endl;
                break;
            }
            curr_month++;
            //carLoan.printStatus();
        }
        cin >> depr_perc;
    }
    
    return 0;
}
