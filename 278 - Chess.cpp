#include <iostream>
#include <math.h> 

using namespace std;

class Queue {
    private:
        struct node {
            node *next;
            int key;
        };
        node *root;
    public:
        Queue() {
            root = NULL;
        }
        int is_empty() { return (root==NULL); }
        void insert(int);
        void eject();
};

void Queue::insert(int data) {
    return;
}

void Queue::eject() {
    return;
}

class Board {
    private:
        int exists[10][10];
        int npieces;
        int nrows;
        int ncols;
        
    public:
        Board(int, int);
        void update_position(int, int);
        int getPieces();
        void fill_knights();
};

Board::Board(int rows, int cols) {
    int i,j;
    npieces = 0;
    nrows = rows;
    ncols = cols;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            exists[i][j] = 0;
        }
    }
}

void Board::update_position(int row, int col) {
    if (row > 0 && row < nrows && col > 0 && col < ncols) {
        exists[row][col] = 1;
        npieces++;
    }
}

int Board::getPieces(void) {
    return npieces;
}

void Board::fill_knights(void) {
    /*
    board.update_position(row-2,row-1);
    board.update_position(row-2,row+1);
    board.update_position(row-1,row-2);
    board.update_position(row-1,row+2);
    board.update_position(row+1,row-2);
    board.update_position(row+1,row+2);
    board.update_position(row+2,row-1);
    board.update_position(row+2,row+1);*/
    return;
}

int main() {
    
   int i, j, n_rows, n_cols, type;
   
   cin >> type >> n_rows >> n_cols;
   Board board(n_rows,n_cols);
   
   if (type == 'k') {
       board.fill_knights();
   }
   


   return 0;
}
