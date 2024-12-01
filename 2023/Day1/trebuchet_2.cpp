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
    if(i>1){
      string sub = str.substr(i-2, 3);
      if(sub == "one"){
        num=10;
        break;
      }
      else if(sub == "two"){
        num=20;
        break;
      }
      else if(sub == "six"){
        num=60;
        break;
      }
    }
    if(i>2){
      string sub = str.substr(i-3, 4);
      if(sub == "four"){
        num=40;
        break;
      }
      else if(sub == "five"){
        num=50;
        break;
      }
      else if(sub == "nine"){
        num=90;
        break;
      }
    }
    if(i>3){
      string sub = str.substr(i-4, 5);
      if(sub == "three"){
        num=30;
        break;
      }
      else if(sub == "seven"){
        num=70;
        break;
      }
      else if(sub == "eight"){
        num=80;
        break;
      }
    }
  }
  for(int i=len-1; i>=0; i--){
    if(i < len-2){
      string sub = str.substr(i, 3);
      if(sub == "one"){
        num = num + 1;
        return num;
      }
      else if(sub == "two"){
        num = num + 2;
        return num;
      }
      else if(sub == "six"){
        num = num + 6;
        return num;
      }
    }
    if(i < len-3){
      string sub = str.substr(i, 4);
      if(sub == "four"){
        num = num + 4;
        return num;
      }
      else if(sub == "five"){
        num = num + 5;
        return num;
      }
      else if(sub == "nine"){
        num = num + 9;
        return num;
      }
    }
    if(i < len-4){
      string sub = str.substr(i, 5);
      if(sub == "three"){
        num = num + 3;
        return num;
      }
      else if(sub == "seven"){
        num = num + 7;
        return num;
      }
      else if(sub == "eight"){
        num = num + 8;
        return num;
      }
    }
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
    GrandTotal = GrandTotal + getNum(line);
  }

  inputFile.close();

  cout<<GrandTotal;
  
  return 0;
}
