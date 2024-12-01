#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int LINE_LEN = 140;

bool isSymbol(string src, int index){
  if(index >= 140 || index < 0 || src.length()==0){
    return false;
  }
  else{
    return !((src[index]=='.') || isdigit(src[index]));
  }
}

bool searchAround(int start, int end, string prev, string curr, string next){
  for(int i=start-1; i<=end+1; i++){
    if(isSymbol(prev, i) || isSymbol(next, i)){
      return true;
    }
  }
  if(isSymbol(curr, start-1) || isSymbol(curr, end+1)){
    return true;
  }
  return false;
}

int validNums(string prev, string curr, string next){

  int indx = 0;
  int lineSum = 0;

  while(indx < LINE_LEN){
    int numb = 0;
    
    if(isdigit(curr[indx])){
      if(isdigit(curr[indx+1])){
        if(isdigit(curr[indx+2])){
          numb =  (curr[indx]-'0')*100 + (curr[indx+1]-'0')*10 + (curr[indx+2]-'0');
          if(searchAround(indx, indx+2, prev, curr, next)){
            lineSum = lineSum + numb;
          }
          indx+=3;
        }
        else{
          numb = (curr[indx]-'0')*10 + (curr[indx+1]-'0');
          if(searchAround(indx, indx+1, prev, curr, next)){
            lineSum = lineSum + numb;
          }
          indx+=2;
        }
      }
      else{
        numb = curr[indx]-'0';
        if(searchAround(indx, indx, prev, curr, next)){
          lineSum = lineSum + numb;
        }
        indx++;
      }
    }
    else{
      indx++;
    }

  }

  return lineSum;
}

int main(){

  fstream inputFile;
  inputFile.open("./gear_ratios_input.txt");

  if(!inputFile.is_open()){
    return 1;
  }
  
  int GrandTotal = 0;
  string prevLine="";
  string currLine="";
  string nextLine="";

  getline(inputFile, currLine);

  for(int i=0; i<140; i++){
    // GrandTotal = GrandTotal + validNums(line);
    getline(inputFile, nextLine);

    GrandTotal = GrandTotal + validNums(prevLine, currLine, nextLine);

    prevLine = currLine;
    currLine = nextLine;
  }

  cout<<GrandTotal<<'\n';

  inputFile.close();
  return 0;
}
