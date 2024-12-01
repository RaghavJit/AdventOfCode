#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

long int searchCategory(int start, int end, long int num){

  ifstream inputFile;
  inputFile.open("./seeds_input.txt");

  if(!inputFile.is_open()){
    return 0;
  }

  string line;
  for(int i=0; i<start; i++){getline(inputFile, line);}
  
  for(int i=start-1; i<end; i++){

    long int source;
    long int destin;
    long int length;

    string s, d, l;
    istringstream iss(line);

    if(iss >> s >> d >> l){
      source = stol(d);
      destin = stol(s);
      length = stol(l);

      if((num>=source) && (num <= source+length-1)){
        return num-source+destin;
      }
    }
    getline(inputFile, line);

  }
  return num;
}

int main(){

  long int seeds_array[] = {3127166940, 109160474, 3265086325, 86449584, 1581539098, 205205726, 3646327835, 184743451, 2671979893, 17148151, 305618297, 40401857, 2462071712, 203075200, 358806266, 131147346, 1802185716, 538526744, 635790399, 705979250};

  int ranges[] = {2, 33, 36, 64, 67, 101, 104, 128, 131, 144, 147, 178, 181, 195};

  long int lowest = 9999999999;

  for(int i=0; i<=20; i++){

    long int seed = seeds_array[i];

    long int num = seed;
    for(int category=0; category<=14; category+=2){
      num = searchCategory(ranges[category], ranges[category+1], num);
    }
    
    cout<<num<<'\n';
    if(num < lowest){
      lowest = num;
    }

  }

  cout<<lowest<<'\n';
  return 0;
}
