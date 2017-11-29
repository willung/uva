#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iomanip>

#define MAX_ROWS 500
#define MAX_COLS 500
using namespace std;

int main()
{
    int n_rows, n_cols;
    int maze[MAX_ROWS][MAX_COLS], n_visits[MAX_ROWS][MAX_COLS];
    char input;

    cin >> n_rows >> n_cols;
    cin.ignore(1,'\n');
    for (int i=0; i<n_rows; i++) {
        for (int j=0; j<n_cols; j++) {
            cin.get(input); 
            maze[i][j] = input - '0';
            //cout << "(" << i << ", " << j << ") = " << maze[i][j] << endl;
            cout << maze[i][j];
        }
        cin.ignore(1,'\n');
        cout<<endl;
    }
    
    
    
    
    return 0;
}
