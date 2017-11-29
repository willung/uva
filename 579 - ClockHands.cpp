#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int hour,minute;
    double ang_hour, ang_minute, ang_btwn;
    
    while(cin >> hour, cin.ignore(1,':'), cin >> minute, hour || minute) {
        ang_hour = 360 * hour/12.0 + 30*minute/60.0;
        ang_minute = 360 * minute/60.0;
        ang_btwn = abs(ang_hour-ang_minute);
        ang_btwn = min(360-ang_btwn,ang_btwn);
        //ang_btwn = abs(min(ang_hour-ang_minute, ang_minute-ang_hour));
        //cout << ang_hour << " " << ang_minute << endl;
        cout << setprecision(3) << fixed;
        cout << ang_btwn << endl;
    }
    
    return 0;
}
