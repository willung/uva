#include <iostream>
#include <math.h>

#define MAX_CHARS 100       // max 100 characters per line

using namespace std;

int getPresses(char input);

int main()
{
   int i,j,sum=0;
   string input;
   
   cin >> n_tcases;
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
    if (input == ' ') { 
        return 1;
    }
    return (int(input)-int('a')) % 3;
}
