#include <iostream>

#define MAX_QUERIES 1000

using namespace std;

class Coordinate {
   private:
      int latitude;   // North-South
      int longitude;  // East-West
      
   public:
      void setLatitude(int lat);
      void setLongitude(int lon);
      void printCoordinate(void);
};

void Coordinate::setLatitude(int lat) {
   latitude = lat;
}

void Coordinate::setLongitude(int lon) {
   longitude = lon;
}

void Coordinate::printCoordinate(void) {
    cout << "Latitude: " << latitude << " Longitude: " << longitude << endl;
}

int main()
{
   Coordinate divisa;
   int n_cases, latitude, longitude;
   
   cin >> n_cases;
   
   cin >> latitude >> longitude;
   divisa.setLatitude(latitude);
   divisa.setLongitude(longitude);
   
   return 0;
}

