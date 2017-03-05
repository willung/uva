#include <iostream>
#include <math.h>

#define MAX_ROW 100       // max 100 rows
#define MAX_COL 100       // max 100 columns

#define SAFESQ '.'
#define MINESQ '*'

using namespace std;

void fillField(int row, int col, char field[MAX_ROW][MAX_COL], int mines[MAX_ROW][MAX_COL],
               int top, int bot, int left, int right);

int main()
{
    char field[MAX_ROW][MAX_COL];
    int mines[MAX_ROW][MAX_COL];
    int i,j,n_rows,n_cols;
    int top,right,bot,left;
    char temp_input;
    while(cin >> n_rows >> n_cols) {
        if (n_rows == 0 && n_cols == 0 ) {
            break;
        }
        for (j=0; j<n_cols; j++) {
            for (i=0; i<n_rows; i++) {
                cin >> temp_input;
                
                //store mines
                if (temp_input == '.') {
                    mines[i][j] = 0;
                } else if (temp_input == '*') {
                    mines[i][j] = 1;
                }
                
                //initialise field
                field[i][j] = '0';
            }
        }
        
        //replace field with numbers
        for (j=0; j<n_cols; j++) {
            for (i=0; i<n_rows; i++) {
                top=1;right=1;left=1;bot=1;
                if (i == 0) { top=0; } 
                if (i == n_rows-1) { bot=0; }
                if (j == 0) { left=0; }
                if (j == n_cols-1) { right=0; }
                
                if (mines[i][j] == 1) {
                    field[i][j] = '*';
                } else {
                    fillField(i,j,field,mines,top,bot,left,right);
                }
            }
        }
        
        //print out field
        for (i=0; i<n_rows; i++) {
            for (j=0; j<n_cols; j++) {
                cout << field[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

void fillField(int row, int col, char field[MAX_ROW][MAX_COL], int mines[MAX_ROW][MAX_COL],
               int top, int bot, int left, int right) {
    field[row][col] += (top+left-top*left)*mines[row-1][col-1];   //top left
    field[row][col] += top*mines[row-1][col];                     //top mid
    field[row][col] += (top+right-top*right)*mines[row-1][col+1]; //top right
    field[row][col] += left*mines[row][col-1];                    //mid left
    field[row][col] += right*mines[row][col+1];                   //mid right
    field[row][col] += (bot+left-bot*left)*mines[row+1][col-1];   //bot left
    field[row][col] += bot*mines[row+1][col];                     //bot mid
    field[row][col] += (bot+right-bot*right)*mines[row+1][col+1]; //bot right
    return;
}
