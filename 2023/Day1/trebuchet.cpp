#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getNum(string str){
  
  int len = str.length();
  int num = 0;

  for(int i=0; i<len; i++){
    if(isdigit(str[i])){
      num = (str[i]-'0')*10;
      break;
    }
  }
  for(int i=len-1; i>=0; i--){
    if(isdigit(str[i])){
      num = num + (str[i] - '0');

      return num;
    }
  }
  return 0;
}

int main(){

  ifstream inputFile;
  inputFile.open("./trebuchet_input.txt");

  if(!inputFile.is_open()){
    return 1;
  }
  
  int GrandTotal = 0;
  string line;
  while(getline(inputFile, line)){
    // cout<<line<<'\n';
    GrandTotal = GrandTotal + getNum(line);
  }

  inputFile.close();

  cout<<GrandTotal;
  
  return 0;
}
