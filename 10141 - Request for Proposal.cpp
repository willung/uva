#include <iostream>
#include <string>

using namespace std;

#define MAX_PROPS 1000
#define MAX_REQS  1000

int main()
{
    int i,j, n_reqs, n_props, reqs_met[MAX_PROPS], max_reqs, final_prop, n_rfp=1;
    float price[MAX_PROPS], min_price;
    string temp, name[MAX_PROPS];
    
    while(cin >> n_reqs >> n_props) {
        cin.ignore(1,'\n');
        
        // signals end
        if (n_reqs == 0 && n_props == 0) {
            break;
        } 
        
        // additional line break between RFP cases
        if (n_rfp > 1) {
            cout << '\n';
        }
        
        for (i=0; i<n_reqs; i++) {
            getline(cin,temp);
            // cout << temp << "\n";
        }
        
        for (i=0; i<n_props; i++) {
            cin >> name[i];
            cin >> price[i] >> reqs_met[i];
            // cout << name[i] << " " << price[i] << " "<< reqs_met[i] << "\n";
            for (j=0; j<=reqs_met[i]; j++) {
                getline(cin,temp);
                // cout << temp << "\n";
            }
        }
        
        final_prop = 0;
        min_price = price[0];
        max_reqs = reqs_met[0];
        for (i=0; i<n_props; i++) {
            if (reqs_met[i] > max_reqs) {
                max_reqs = reqs_met[i];
                min_price = price[i];
                final_prop = i;
            }
            
            if (price[i] < min_price && reqs_met[i] == max_reqs) {
                min_price = price[i];
                final_prop = i;
            }
        }
        
        cout << "RFP #" << n_rfp << '\n';
        cout << name[final_prop] << '\n';
        n_rfp++;
    }
    
    return 0;
}
