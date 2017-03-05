#include <iostream>
#include <math.h>

#define MAX_ROW 100       // max 100 rows
#define MAX_COL 100       // max 100 columns

#define SAFESQ '.'
#define MINESQ '*'

using namespace std;

int main()
{
    int[MAX_ROW][MAX_COL] field, mines;
    int i,j, row, col, temp_input;
    while(cin >> row >> col) {
        if (row == 0 && col == 0 ) {
            break;
        }
        for (j=0; j<col; j++) {
            for (i=0; i<row; i++) {
                cin >> temp_input;
                
                //store mines
                if (temp_input == SAFESQ) {
                    mines[i][j] = 0;
                } else if (temp_input == MINESQ) {
                    mines[i][j] = 1;
                }
                cout << mines[i][j];
                //initialise field
                field[i][j] = 0;
            }
            cout << endl;
        }
        
        
    }
    return 0;
}
