#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

string PATH = "./haunted_input.txt";
string DIRCS = "LLRLRRRLLRRRLRRLRRLRLRRRLRRRLRLLRLRRLRRLRLLRRLRRRLRRLRLRLRLRRRLRRLRLLLRRLRRRLLLRLRRRLRRRLLRRLRRRLRLRRRLLLRRLLRRLRRLLLRRRLRRRLRRRLRRLLRLRLRLRRRLRLRLRRLRRLRLRRRLRRLRRRLRRRLLLRLRRLRRLRLLRRLLRRLRRLLRLRRLRRLRLRLLLRLLRRLRRLRRRLLRRLLRRRLRRLRRRLRRRLLRRRLRRRLLRRRLRLRLLRRLRLRLRRRR";
int DIR_LEN = 271;

struct dirs{
  string L="";
  string R="";
};

int main(){

  ifstream inputFile;
  inputFile.open(PATH);

  if(!inputFile.is_open()){
    return 1;
  }
  
  unordered_map<string, dirs> umap;

  string line;
  while(getline(inputFile, line)){
    dirs drs;
    drs.L = line.substr(7, 3);
    drs.R = line.substr(12, 3);

    umap[line.substr(0, 3)] = drs;
  }


  string str_arr[6] = {"AAA", "TGA", "BJA", "MLA", "BQA", "MJA"};

  for(int i=0; i<6; i++){
    int indx = 0, count = 1;
    string str = str_arr[i];

    while(true){
      auto it = umap.find(str);
      str = (DIRCS[indx] == 'L') ? it->second.L : it->second.R;

      if(str[2] == 'Z'){
        cout<<count<<'\n';
        break;
      }

      count++;
      indx++;
      if(indx == DIR_LEN){
        indx = 0;
      }
    }
  }


  inputFile.close();

  return 0;
}
