#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int i, key = int('i')-int('p');
    string input, replacechar;
    
    while(getline(cin,input)) {
        for (i=0; i<input.length(); i++) {
            replacechar = string(1,int(input[i])+key);
            input.replace(i,1,replacechar);
        }
        cout << input << endl;
    }
}
