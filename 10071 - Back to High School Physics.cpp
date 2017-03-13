#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int init_velocity,init_time;
    while(cin >> init_velocity >> init_time) {
        cout << init_velocity * init_time * 2 << endl;
    }
}
