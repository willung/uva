#include <iostream>
#include <string>

using namespace std;

int getReplaceStr(char input);

int main()
{
   int i, j, n_inputs=1, n_cases, lower_input, upper_input, is_unique=0;
   string input, openquote = "``", closequote = "''";
   
   while(cin >> input) {
       cout << "Case " << n_inputs << ":" << endl;
       n_inputs++;
       cin >> n_cases;
       for (i=0; i<n_cases; i++) {
           
           is_unique=1;
           cin >> lower_input >> upper_input;
           if (lower_input > upper_input) {
                swap(lower_input, upper_input);
           }
           
           if (upper_input > input.length()) {
               upper_input = input.length();
           }
           
           for (j=lower_input; j<=upper_input; j++) {
               if (input[j] != input[lower_input]) {
                   is_unique=0;
                   break;
               }
           }
           
           if (is_unique) {
               cout << "Yes" << endl;
           } else {
               cout << "No" << endl;
           }
           
        }
    }
   return 0;
}
