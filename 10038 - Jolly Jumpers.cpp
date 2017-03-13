#include <iostream>
#include <math.h> 
#include <limits>

#define MAX_SEQ 3000

using namespace std;

int main()
{
   int i, seq_length, curr_seq, last_seq, abs_diff, seq[MAX_SEQ], test;
   
   //seq_length = n
   while(cin >> seq_length) {
       
       //Sequence of one integer automatically 'Jolly'
       if (seq_length == 1) {
            cout << "Jolly" << endl;
       }
       
       //store zeroes into indexes 1 to (n-1) 
       for (i=1; i<seq_length; i++) {
           seq[i] = 0;
       }
       
       //store first term into last_seq
       cin >> last_seq;
       
       //calculate absolute diff for successive terms 
       for (i=1; i<seq_length; i++) {
           cin >> curr_seq;
           abs_diff = fabs(curr_seq-last_seq);
           
           //'Not Jolly' if abs_diff is duplicate or bigger than (n-1)
           if (seq[abs_diff] == 1 || abs_diff > seq_length-1) {
               cout << "Not jolly" << endl;
               //ignore rest of input line (max chars until '\n' reached)
               cin.ignore(numeric_limits<streamsize>::max(),'\n');
               break;
           } else {
               seq[abs_diff] = 1;
           }
           last_seq = curr_seq;
           
           //Jolly if it reaches last integer without duplicate abs diff values
           if (i == seq_length-1) {
               cout << "Jolly" << endl;
           }
       }
       
       /*
       for (i=1; i<seq_length; i++) {
            cout << "seq[" << i << "]: "<<seq[i] << endl;
       }
       */
       
   }
    
   return 0;
}

