#include <iostream>
#include <math.h> 

#define MAX_SEQ 3000

using namespace std;

int main()
{
   int i, seq_length, curr_seq, last_seq, abs_diff, seq[MAX_SEQ], test;
   
   //seq_length = n
   while(cin >> seq_length) {
   
       //store 1 to (n-1) into indexes 1 to (n-1) 
       for (i=1; i<seq_length; i++) {
           seq[i] = i;
       }
       
       //store first term into last_seq
       cin >> last_seq;
       
       //calculate absolute diff for successive terms 
       for (i=1; i<seq_length; i++) {
           cin >> curr_seq;
           abs_diff = fabs(curr_seq-last_seq);
           
           //'Not Jolly' if abs_diff is duplicate or bigger than (n-1)
           if (seq[abs_diff] == 0 || abs_diff > seq_length-1) {
               cout << "Not jolly" << endl;
               //ignore rest of input line
               cout << "i:" << i << " " << abs_diff << endl;
               cout << seq_length <<endl;
               cin.ignore(seq_length-i,'\n');
               break;
           } else {
               seq[abs_diff] = 0;
           }
           last_seq = curr_seq;
           
           //Jolly if it reaches last integer without duplicate abs diff values
           if (i == seq_length-1) {
               cout << "Jolly" << endl;
           }
       }
       
   }
    
   return 0;
}

