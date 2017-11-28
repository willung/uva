#include <iostream>

using namespace std;

int main()
{
   int wall_dist=1, climb_dist, fall_dist, fatigue;
   double curr_dist=0, curr_day;
   
   while(1) {
        cin >> wall_dist >> climb_dist >> fall_dist >> fatigue;
        
        curr_dist = 0, curr_day=1;
        if (wall_dist == 0) break;
        
        while(1) {
            curr_dist += climb_dist*(1-(curr_day-1)*fatigue*1.0/100);
            cout << "day " << curr_day << ", dist: " << curr_dist << "\n";
            if (curr_dist <= 0) {
                cout << "failure on day " << curr_day << "\n";
                break;
            } else if (curr_dist < wall_dist) {
                cout << "success on day " << curr_day-1 << "\n";
                break;
            } else {
                curr_dist -= fall_dist;
                curr_day += 1;
            }
        }
   }
   return 0;
}
