#include <iostream>
#include <math.h>
#include <limits>

#define MAX_PPL 200     // max participants
#define MIN_PPL 1
#define MAX_BGT 500000 // max budget
#define MIN_BGT 1
#define MAX_HTL 18      // max hotels
#define MIN_HTL 1
#define MAX_WKS 13      // max weeks
#define MIN_WKS 1
#define MAX_PRC 10000   // max price per person
#define MIN_PRC 1
#define MAX_BED 1000    // max beds
#define MIN_BED 0

using namespace std;

int in_bounds(int input, int lower, int upper) {
    return (lower <= input) && (input <= upper);
}

int main()
{
    int i, j, n_participants, budget, n_hotels, n_weeks, price, n_beds, min_cost;
    
    
    while(cin >> n_participants >> budget >> n_hotels >> n_weeks) {
        min_cost = numeric_limits<int>::max();
        if (!in_bounds(n_participants,MIN_PPL,MAX_PPL) ||
            !in_bounds(budget,MIN_BGT,MAX_BGT) ||
            !in_bounds(n_hotels,MIN_HTL,MAX_HTL) ||
            !in_bounds(n_weeks,MIN_WKS,MAX_WKS)) {
                cout << "Error: Input data out of bounds" << endl;
            }
        
        for (i=0; i<n_hotels; i++) {
            cin >> price;
            
            //error check
            if (!in_bounds(price,MIN_PRC,MAX_PRC)) {
                cout << "Error: Input price out of bounds" << endl;
                break;
            }
            
            //budget exceeded
            if (n_participants * price > budget) {
                //ignore line of bed values
                cin.ignore();
                cin.ignore(numeric_limits<int>::max(),'\n');
                continue;
            }
            
            for (j=0; j<n_weeks; j++) {
                cin >> n_beds;
                
                //error check
                if (!in_bounds(n_beds,MIN_BED,MAX_BED)) {
                    cout << "Error: Input beds out of bounds" << endl;
                    break;
                }
                
                //if there's enough beds
                if (n_beds >= n_participants) {
                    min_cost = min(min_cost, price*n_participants);
                }
            }
            
        }
        
        if (min_cost != numeric_limits<int>::max()) {
            cout << min_cost << endl;
        } else {
            cout << "stay home" << endl;
        }
    }
   
   return 0;
}

