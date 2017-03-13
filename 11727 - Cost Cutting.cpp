#include <iostream>
#include <math.h>

#define NO_INPUTS 2

using namespace std;

int main()
{
    int i, n_cases, inputs[NO_INPUTS];
    cin >> n_cases;
    for (i=0; i<n_cases; i++) {
        cin >> inputs[0] >> inputs[1];
        if (inputs[0] < inputs[1]) {
            cout << '<' << endl;
        } else if (inputs[0] > inputs[1]) {
            cout << '>' << endl;
        } else {
            cout << '=' << endl;
        }
    } 
}
