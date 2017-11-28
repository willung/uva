#include <iostream>

using namespace std;

int main()
{
   int wall_dist=1, climb_dist, fall_dist, fatigue;
   double curr_dist=0, curr_day;
   
   while(1) {
        cin >> wall_dist >> climb_dist >> fall_dist >> fatigue;
        if (wall_dist == 0) {
            break;
        }
        curr_dist = 0, curr_day=1;
        while(curr_dist < wall_dist) {
            curr_dist += climb_dist*(1-fatigue/100*curr_day) - fall_dist;
            if (curr_dist <= 0) {
                cout << "failure on day" << curr_day << "\n";
                break;
            } else {
                curr_day += 1;
            }
        }
        cout << "success on day " << curr_day-1 << "\n";
   }
   return 0;
}
