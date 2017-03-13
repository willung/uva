#include <iostream>
#include <math.h>

#define MAX_CHARS 100       // max 100 characters per line

using namespace std;

int getPresses(char input);

int main()
{
   int i,j,sum=0, n_tcases;
   string input;
   
   cin >> n_tcases;
   cin.ignore();
   for (i=0; i<n_tcases; i++) { 
       getline(cin,input);
       
       // Calculate sum key press of each letter
       sum=0;
       for (j=0; j<input.length(); j++) {
           sum += getPresses(input[j]);
       }
       cout << "Case #" << i+1 << ": " << sum << endl;
   }
   return 0;
}

int getPresses(char input) {
    int initial_press=0;
    if (input == ' ') { 
        return 1;
    }
    
    if (input < 's' ) {
        // %3 divides into groups of 3 letters, results in 0, 1 or 2
        return (int(input)-int('a')) % 3 + 1;
    } else {
        if (input == 's') {
            return (int(input)-int('s')) % 4 + 4;
        } else if (input < 'w') {
            return (int(input)-int('s')) % 4;
        } else {
            return (int(input)-int('s')) % 4 + 1;
        }
        
    }
}
