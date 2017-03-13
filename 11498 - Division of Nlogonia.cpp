#include <iostream>

#define MAX_COORDS 1000

using namespace std;

class Coordinate {
   private:
      int latitude;   // North-South
      int longitude;  // East-West
      
   public:
      void setLatitude(int lat);
      void setLongitude(int lon);
      void printCoordinate(void);
      void compare(Coordinate coord);
};

void Coordinate::setLatitude(int lat) {
   latitude = lat;
}

void Coordinate::setLongitude(int lon) {
   longitude = lon;
}

void Coordinate::printCoordinate(void) {
    cout << "Longitude: " << longitude << " Latitude: " << latitude << endl;
}

void Coordinate::compare(Coordinate coord) {
    //check if it's on divisa
    if (this->latitude == coord.latitude || this -> longitude == coord.longitude) {
        cout << "divisa" << endl;
    } 
    
    //check for North or South of divisa
    if (this->latitude > coord.latitude) {
        cout << "N";
    } else {
        cout << "S";
    }
    
    //check for East or West of divisa
    if (this->longitude > coord.longitude) {
        cout << "E" << endl;
    } else {
        cout << "O" << endl;
    }
}

int main()
{
   Coordinate divisa, coords;
   int i, n_queries, latitude, longitude;
   
   //get K, number of queries 
   while (cin >> n_queries) {
       
       //end of input indicated by number 0
       if (n_queries == 0 ) {
           break;
       }
   
       //store coordinates of divisa
       cin >> longitude >> latitude;
       divisa.setLongitude(longitude);
       divisa.setLatitude(latitude);
       
       //output for each coordinate
       for (i=0; i<n_queries; i++) {
           cin >> longitude >> latitude;
           coords.setLatitude(latitude);
           coords.setLongitude(longitude);
           coords.compare(divisa);
       }
   }

   return 0;
}

