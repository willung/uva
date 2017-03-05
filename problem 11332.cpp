#include <iostream>
#include <math.h>

#define MAX_DIGITS 10   // max 10 digits per integer 
#define NO_INPUTS 2     // 2 integer inputs
using namespace std;

int getDigit(int input, int n);

int getNumDigits(int input);

int sumDigits(int input);

int main()
{
   int i, input;

   while (cin >> input) {
        cout << sumDigits(input) << endl;
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


// return sum of digits for input 
int sumDigits(int input) {
    int i,sum=0;
    if (getNumDigits(input) == 1) {
        return input;
    } else {
        for (i=1; i<=getNumDigits(input); i++) {
            sum += getDigit(input, i);
        }
        return sumDigits(sum);
    }
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
