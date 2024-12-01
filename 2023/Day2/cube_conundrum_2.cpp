#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int RED = 12;
int GREEN = 13;
int BLUE = 14;

int power(string str, int GameCount){

  int indx = 0;
  int max_red = 0;
  int max_green = 0;
  int max_blue = 0;

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

    int is_digit = (int)isdigit(str[indx+1]);

    int num = (is_digit==1) ? (str[indx]-'0')*10 + (str[indx+1]-'0') : (str[indx]-'0');
    cout<<num<<" ";
    switch(str[indx+2+is_digit]){
      case 'r':
        max_red = (num>max_red) ? num : max_red;
        indx = indx + 7 + is_digit; 
        break;
      case 'g':
        max_green = (num>max_green) ? num : max_green;
        indx = indx + 9 + is_digit; 
        break;
      case 'b':
        max_blue= (num>max_blue) ? num : max_blue;
        indx = indx + 8 + is_digit;
        break;
    }
  }

  return max_red*max_blue*max_green;
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
    GrandTotal = GrandTotal + power(line, GameCount);
    cout<<power(line, GameCount)<<'\n';
    GameCount++;
  }

  cout<<GrandTotal<<'\n';

  inputFile.close();

  return 0;
}
