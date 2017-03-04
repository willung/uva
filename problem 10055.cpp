#include <iostream>
#include <math.h>
#include <iomanip>

#define NO_INPUTS 2

using namespace std;

int main()
{
   long int inputs[NO_INPUTS];
   
   cout<< fixed;
   cout<< setprecision(0);
   while (cin >> inputs[0] >> inputs[1]) {
       cout << fabs(inputs[0]-inputs[1]) << endl;
   }
}
