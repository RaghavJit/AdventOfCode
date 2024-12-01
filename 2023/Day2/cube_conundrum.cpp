#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int RED = 12;
int GREEN = 13;
int BLUE = 14;

int check(string str, int GameCount){

  int indx = 0;
  
  if(GameCount <= 9){
    indx = 8;
  }
  else if(GameCount > 9 && GameCount <= 99){
    indx = 9;
  }
  else if(GameCount == 100){
    indx = 10;
  }

  while(indx < str.length()){
    if(isdigit(str[indx+1])){
      switch(str[indx+3]){
        case 'r':
          if((str[indx]-'0')*10 + (str[indx+1]-'0') > RED){
            return 0;
          }
          break;
        case 'g':
          if((str[indx]-'0')*10 + (str[indx+1]-'0') > GREEN){
            return 0;
          }
          break;
        case 'b':
          if((str[indx]-'0')*10 + (str[indx+1]-'0') > BLUE){
            return 0;
          }
          break; 
      }
    }

    switch(str[indx+2+(int)isdigit(str[indx+1])]){
      case 'r':
        indx = indx + 7 + (int)isdigit(str[indx+1]);
        break;
      case 'g':
        indx = indx + 9 + (int)isdigit(str[indx+1]);
        break;
      case 'b':
        indx = indx + 8 + (int)isdigit(str[indx+1]);
        break;
    }
  }

  return GameCount;
}

int main(){

  fstream inputFile;
  inputFile.open("./cube_conundrum_input.txt");

  if(!inputFile.is_open()){
    return 1;
  }
  
  int GrandTotal = 0;
  int GameCount = 1;
  string line;
  while(getline(inputFile, line)){
    // cout<<line<<'\n';
    GrandTotal = GrandTotal + check(line, GameCount);
    cout<<check(line, GameCount)<<'\n';
    GameCount++;
  }

  cout<<GrandTotal<<'\n';

  inputFile.close();

  return 0;
}
