#include <iostream>
#include <time.h>

#define MAX_DUR  100             //loans at most 100 months long
#define MAX_DEPR 100

using namespace std;

class Loan {
    private:
        double loan_value;
        double car_value;
        int duration;           //duration of loan in months
        double repayment;       //amount of each repayment
        int interest_rate;      //interest rate on total value
        
    public:
        void setInitial(double value, int dur, double downpay, int interest);
        void updateRepayment(double payment, int dur);
        void updateDepreciation(double depr_perc, int dur);
        void updateDuration(int dur);
        void printStatus(void);
        int  loanLessThanCar(void);
};

//set Initial terms of the loan
void Loan::setInitial(double value, int dur, double downpay, int interest) {
    duration = dur;
    interest_rate = interest;
    repayment = value/dur;
    loan_value = value;
    car_value = value+downpay;      //downpayment equal to one repayment

}

//update loan value after repayments
void Loan::updateRepayment(double payment, int dur) {
    loan_value -= payment*dur;
}

//update car value after depreciation
void Loan::updateDepreciation(double depr_perc, int dur) {
    car_value *= dur*(1-depr_perc);
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
    int i, j, interest=1, duration, n_deprs, curr_month, 
        curr_depr_month, next_depr_month;
    double value, downpayment, repayment, depr_perc, unused_depr;
    Loan carLoan;
    
    while(cin >> duration >> downpayment >> value >> n_deprs) {
        if (duration < 0) {
            break;
        }

        repayment = value/duration;
        carLoan.setInitial(value,duration,downpayment,1);
        //carLoan.printStatus();

        //initial depreciation
        curr_month=0; 
        cin >> curr_depr_month >> depr_perc;
        cin >> next_depr_month;
        n_deprs--;
        
        while(curr_month <= MAX_DUR) {
            if (curr_month == next_depr_month) {
                //update depreciation month, percentage and month of next depr rate
                curr_depr_month = next_depr_month;
                cin >> depr_perc;
                if (n_deprs == 1) {
                    next_depr_month = MAX_DUR;
                } else {
                    cin >> next_depr_month;
                }
                n_deprs--;
            }
            
            carLoan.updateDepreciation(depr_perc, 1);
            if (curr_month > 0) {
                carLoan.updateRepayment(repayment, 1);
                carLoan.updateDuration(1);
            }
            carLoan.printStatus();
            if (carLoan.loanLessThanCar()) {
                cout << curr_month;
                if (curr_month == 1) {
                    cout << " month" << endl;
                } else {
                    cout << " months" << endl;
                }    
                
                //cycle through unused deprec values 
                for (i=0; i<2*n_deprs-1; i++) {
                    cin >> unused_depr;
                }
                break;
            }
            curr_month++;
        }
    }
    return 0;
}
