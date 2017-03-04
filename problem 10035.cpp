#include <iostream>
#include <math.h>

#define MAX_DIGITS 10   // max 10 digits per integer 
#define NO_INPUTS 2     // 2 integer inputs
using namespace std;

int getDigit(int input, int n);

int getNumDigits(int input);

void printResult(int n);

int main()
{
   int i, inputs[NO_INPUTS], n_digits[NO_INPUTS], min_digits,
       digit, n_carries=0, carry=0, total;

   while (cin >> inputs[0] >> inputs[1]) {
       n_carries = 0;
       if (inputs[0] == 0 && inputs[1] == 0) {
           break;
       } else {
           // calculate number of digits for each input, store minimum
           min_digits = 0;
           for (i=0; i<NO_INPUTS; i++) {
                n_digits[i] = getNumDigits(inputs[i]);
                if (min_digits < n_digits[i]) {
                    min_digits = n_digits[i];
                }
           }
           
           //calculate if sum of digits carry over
           carry=0;
           for (i=1; i<=min_digits; i++) {
                total = getDigit(inputs[0],i) + getDigit(inputs[1],i);
                if (total + carry >= 10) {
                    n_carries++;
                }
                carry = int((total + carry)/ 10);
           }
           
           //if one number has more digit, check for carry over
           for (i=0; i<NO_INPUTS; i++) {
               if (n_digits[i] > min_digits && 
                    getDigit(inputs[i],min_digits+1) + carry >= 10) {
                   n_carries++;
               }
           }
       }
       printResult(n_carries);
   }
   
}

// return nth digit for input 
int getDigit(int input, int n) {
    int digit;
    // left truncate at (n+1)th digit from right 
    digit = input % int(pow(10,n));
    // right truncate at second digit from left 
    digit = int(digit / pow(10,n-1));
    return digit; 
}

// return number of digits for input 
int getNumDigits(int input) {
    int i;
    for (i=1; i<MAX_DIGITS; i++) {
        if (input == input % int(pow(10,i))) {
            return i; 
        }
    }
}

void printResult(int n) {
    if (n<0) {
        return;
    }
    if (n==0) {
        cout << "No carry operation." << endl;
    } else if (n==1) {
        cout << "1 carry operation." << endl;
    } else {
        cout << n << " carry operations." << endl;
    }
    return;
}

    /* looping to get digits for a single number
    for (i=0; i<MAX_DIGITS; i++) {
       digit = input % int(pow(10,i+1));
       if (digit == input) {
           lastdigit = 1;
       } 
       digit = int(digit / pow(10,i));
       cout << digit << endl;
       
       if (lastdigit) {
           break;
       }    
   } */
   
   /* using array to get digits for a single number
   
   int i, input=579, digits[MAX_DIGITS], n_digits=1, output=1;
   for (i=0; i<MAX_DIGITS; i++) {
       digits[i] = input % int(pow(10,i+1));
       cout << digits[i] << endl;
       if (digits[i] == input) {
           break;
       } 
   }
   n_digits = i;
   
   for (i=n_digits-1; i>=0; i--) {
       if (i==0) {
           
       output = (digits[i] - digits[i-1]);
       cout << output << endl;
   }
   return 0;
   
   */
