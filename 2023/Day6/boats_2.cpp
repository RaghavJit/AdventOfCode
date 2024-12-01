#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long int getMargin(long int time, long int record){
  long double D = sqrt((time*time) - (4*record));

  cout<<floor((time+D)/2)<<" "<<floor((time-D)/2)<<'\n';
  return floor((time+D)/2) - floor((time-D)/2);
}

int main(){
  int times[4] = {47, 98, 66, 98}; 
  int records[4] = {400, 1213, 1011, 1540};

  cout<<getMargin(47986698, 400121310111540)<<'\n';
  return 0;
}
