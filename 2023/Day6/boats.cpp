#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int getMargin(int time, int record){
  return floor((time+sqrt((time*time) - (4*record)))/2) - floor((time-sqrt((time*time) - (4*record)))/2);
}

int main(){
  int times[4] = {47, 98, 66, 98}; 
  int records[4] = {400, 1213, 1011, 1540};

  int GrandTotal = 1;
  for(int i=0; i<4; i++){
    int temp = getMargin(times[i], records[i]);
    cout<<temp<<'\n';
    GrandTotal = GrandTotal * temp;
  }
  cout<<GrandTotal;
  return 0;
}
