#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class range{
  public:
    long int start = 0;
    long int end = 0;

    range(long int s, long int e){
      start = s;
      end = e;
    }
};

range searchCategory(int start, int end, range rng){

  ifstream inputFile;
  inputFile.open("./seeds_input.txt");

  if(!inputFile.is_open()){
    return 0;
  }

  range result(0, 0);

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

      if((rng.start >= source) && (rng.start <= source+length-1) && (rng.end <=source+length-1)){
        return num-source+destin;
      }
      else()
    }
    getline(inputFile, line);

  }
  return rng;
}

long int searchAllCategory(range nums, int* category_ranges){
  
  range rng(nums.start, nums.end);

  for(int category=0; category<=14; category+=2){
    rng = searchCategory(category_ranges[category], category_ranges[category+1], rng);
  }
  return rng.start;
}

int main(){

  long int seeds_array[] = {3127166940, 109160474, 3265086325, 86449584, 1581539098, 205205726, 3646327835, 184743451, 2671979893, 17148151, 305618297, 40401857, 2462071712, 203075200, 358806266, 131147346, 1802185716, 538526744, 635790399, 705979250};

  int category_ranges[] = {2, 33, 36, 64, 67, 101, 104, 128, 131, 144, 147, 178, 181, 195};

  long int lowest = 9999999999;

  for(int i=0; i<=20; i++){

    long int seed = seeds_array[i];

    long int num = searchAllCategory(seed, category_ranges);
    
    cout<<num<<'\n';
    if(num < lowest){
      lowest = num;
    }

  }

  cout<<lowest<<'\n';
  return 0;
}
