#include <iostream>

using namespace std;

int GetCycleNumber(int n, int cycle);

int main()
{
   int input=1, lower_input, upper_input, cycles=1, max_cycles=1;
   
   while (cin >> lower_input >> upper_input) {
       max_cycles=1;
       
       #Print input
       cout << lower_input << " " << upper_input << " ";
       
       #Swap inputs to match lower and upper bounds
       if (lower_input > upper_input) {
           swap(lower_input, upper_input);
       }
       
       #Cycle through integers to find max cycle
       for (input = lower_input; input <= upper_input; input++ ) {
           cycles = GetCycleNumber(input,1);
           if (max_cycles < cycles) {
                max_cycles = cycles;
           }
       }
       
       #Print Max Cycle results
       cout << max_cycles << endl;
   }
   
   return 0;
}

int GetCycleNumber(int n, int cycle) {
    if (n == 1) {
        return cycle;
    } 
    if ( n % 2 == 1 ) {
       return GetCycleNumber(3*n + 1, cycle+1);
    } else {
       return GetCycleNumber(n / 2, cycle+1);
    }
}
