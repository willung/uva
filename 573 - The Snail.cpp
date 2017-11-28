#include <iostream>

using namespace std;

int main()
{
   int wall_dist=1, climb_dist, fall_dist, fatigue;
   double newclimb_dist, curr_dist=0, curr_day;
   
   while(1) {
        cin >> wall_dist >> climb_dist >> fall_dist >> fatigue;
        
        curr_dist = 0, curr_day=1;
        if (wall_dist == 0) break;
        
        while(1) {
            newclimb_dist = climb_dist*(1-(curr_day-1)*fatigue/100);
            curr_dist += newclimb_dist*(newclimb_dist > 0);
            // cout << "day " << curr_day << ", dist: " << curr_dist << "\n";
            if (curr_dist > wall_dist) {
                cout << "success on day " << curr_day << "\n";
                break;
            }
            
            curr_dist -= fall_dist;

            if (curr_dist < 0) {
                cout << "failure on day " << curr_day << "\n";
                break;
            } 
            
            curr_day += 1;
        }
   }
   return 0;
}
