#include <iostream>
#include <string>

#define NO_KEYS 47

using namespace std;

string getReplaceStr(char input);

int main()
{
   int i, index;
   string input;
   
   while(getline(cin,input)) {
       if (input[i] == ' ') {
           cout << ' ';
       }
       for (i=0; i<input.length(); i++) {
            input.replace(i,1,getReplaceStr(input[i]));
       }
       cout << input;
   }
   return 0;
}

string getReplaceStr(char input) {
    int i;
    char keys[NO_KEYS] = {'`','1','2','3','4','5','6','7','8','9','0','-','=',
                          'Q','W','E','R','T','Y','U','I','O','P','[',']','\\',
                          'A','S','D','F','G','H','J','K','L',';','\'',
                          'Z','X','C','V','B','N','M',',','.','/'};
    for (i=1; i<NO_KEYS; i++) {
        if (tolower(keys[i]) == tolower(input)) {
            if (islower(input)) {
                return string(1,tolower(keys[i-1]));
            } else {
                return string(1,keys[i-1]);
            }
        }
        
    }
}
