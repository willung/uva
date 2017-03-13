#include <iostream>
#include <math.h>

#define MAX_TCASES 50       // max 50 test cases
#define MAX_STUDENTS 10000  //max 10000 students running

using namespace std;

int main()
{
   int i, j, n_tcases=0, n_students=0, max_speed=0, temp_speed;

   cin >> n_tcases;
   for (i=0; i<n_tcases; i++) { 
       cin >> n_students; 
       max_speed = 0;
       for (j=0; j<n_students; j++) {
           cin >> temp_speed;
           if (temp_speed > max_speed) {
               max_speed = temp_speed;
           }
       }
       cout << "Case " << i+1 << ": " << max_speed << endl;
   }
   return 0;
}
