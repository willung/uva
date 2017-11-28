#include <iostream>
#include <string>

using namespace std;

#define MAX_PROPS 1000
#define MAX_REQS  1000

int main()
{
    int i,j, n_reqs, n_props;
    float price[MAX_PROPS], reqs_met[MAX_PROPS];
    string temp, name[MAX_PROPS];
    cin >> n_reqs >> n_props;
    for (i=0; i<=n_reqs; i++) {
        getline(cin,temp);
        // cout << temp << "\n";
    }
    
    for (i=0; i<=n_props; i++) {
        cin >> name[i];
        cin >> price[i] >> reqs_met[i];
        cout << name[i] << " " << price[i] << " "<< reqs_met[i] << "\n";
        for (j=0; j<=reqs_met[i]; j++) {
            getline(cin,temp);
            // cout << temp << "\n";
        }
    }
    
    return 0;
}
