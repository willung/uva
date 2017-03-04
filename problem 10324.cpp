#include <iostream>
#include <string>

using namespace std;

int getReplaceStr(char input);

int main()
{
   int i, j, n_cases, lower_input, upper_input, is_unique=0;
   string input, openquote = "``", closequote = "''";
   
   while(getline(cin,input)) {
       cin >> n_cases;
       for (i=0; i<n_cases; i++) {
           cout << "Case " << i << ":" << endl;
           
           is_unique=1;
           cin >> lower_input >> upper_input;
           if (lower_input > upper_input) {
                swap(lower_input, upper_input);
           }
           
           if (upper_input > input.length()) {
               upper_input = input.length();
           }
           
           for (j=lower_input; j<upper_input; j++) {
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
