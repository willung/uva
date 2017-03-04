#include <iostream>
#include <string>

using namespace std;

string getReplaceStr(char input);

int main()
{
   int i, index, open=1;
   string input, openquote = "``", closequote = "''";
   
   while(getline(cin,input)) {
       for (i=0; i<input.length(); i++) {
            if (input[i] == '"') {
                if (open) {
                    input.replace(i,1,openquote);
                    open=0;
                } else {
                    input.replace(i,1,closequote);
                    open=1;
                }
            }
       }
       cout << input << endl;
   }
   return 0;
}
