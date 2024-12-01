#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int LINE_LEN = 140;

int explore(string str, int index){
  bool left = isdigit(str[index-1]);
  bool rigt = isdigit(str[index+1]);
  // cout<<"fucn"<<str;
  if(left && rigt){
    return (str[index-1]-'0')*100 + (str[index]-'0')*10 + (str[index+1]-'0');
  }
  else if(left && !rigt){
    if(isdigit(str[index-2])){
      return (str[index-2]-'0')*100 + (str[index-1]-'0')*10 + (str[index]-'0');
    }
    return (str[index-1]-'0')*10 + (str[index]-'0');
  }
  else if(!left && rigt){
    if(isdigit(str[index+2])){
      return (str[index+2]-'0') + (str[index+1]-'0')*10 + (str[index]-'0')*100;
    }
    return (str[index+1]-'0') + (str[index]-'0')*10;
  }
  else if(!left && !rigt){
    return (str[index]-'0');
  }
  return -1;
}

int validNums(string prev, string curr, string next){

  int lineSum = 0;

  for(int indx=0; indx<LINE_LEN; indx++){

    int numb1 = 0;
    int numb2 = 0;

    if(curr[indx]!='*'){continue;}

    string src = prev.substr(indx-3, 7);
    if(src.substr(2, 3) != "..."){
      bool here = false;
      for(int i=2; i<=4; i++){
        if(isdigit(src[i])){
          int temp = 0;
          temp = explore(src, i);
          if(temp>0){
            if(temp != numb1 && numb1 == 0){
              numb1=temp;
              here = true;
            } 
            else if(temp != numb1){
              numb2=temp;
              here = true;
            }
            else if(temp == numb1 && !here){
              numb2 = temp;
            }
          }
        }
        if(numb1!=0 && numb2!=0){
      cout<<numb1<<"  "<<numb2<<'\n';
          lineSum = lineSum + numb1*numb2;
          break;
        }
      }
    }

    src = next.substr(indx-3, 7);
    if(src.substr(2, 3) != "..."){
      bool here = false;
      for(int i=2; i<=4; i++){
        if(isdigit(src[i])){
          int temp = 0;
          temp = explore(src, i);
          if(temp>0){
            if(temp != numb1 && numb1 == 0){
              numb1=temp;
              here = true;
            } 
            else if(temp != numb1){
              numb2=temp;
              here = true;
            }
            if(temp == numb1 && !here){
              numb2 = temp;
            }
          }
        }
        if(numb1!=0 && numb2!=0){
      cout<<numb1<<"  "<<numb2<<'\n';
          lineSum = lineSum + numb1*numb2;
          break;
        }
      }
    }


    src = curr.substr(indx-3, 7);
    bool here = false;
    if(isdigit(curr[indx-1])){
      int temp = 0;
      temp = explore(src, 2);
      if(temp>0){
        if(temp != numb1 && numb1 == 0){
          numb1=temp;
          here = true;
          if(numb1!=0 && numb2!=0){
            
            cout<<numb1<<"  "<<numb2<<'\n';
            lineSum = lineSum + numb1*numb2;
          }
        } 
        else if(temp != numb1){
          numb2=temp;
          here = true;
          if(numb1!=0 && numb2!=0){
            
            cout<<numb1<<"  "<<numb2<<'\n';
            lineSum = lineSum + numb1*numb2;
          }
        }
        else if(temp == numb1 && !here){
          numb2 = temp;
        }
      }
    }

    if(isdigit(curr[indx+1])){
      int temp = 0;
      temp = explore(src, 4);
      if(temp>0){
        if(temp != numb1 && numb1 == 0){
          numb1=temp;
          here = true;
          if(numb1!=0 && numb2!=0){
            
            cout<<numb1<<" mih "<<numb2<<'\n';
            lineSum = lineSum + numb1*numb2;
          }
        } 
        else if(temp != numb1){
          numb2=temp;
          here = true;
          if(numb1!=0 && numb2!=0){
            
                    if(indx == 71){cout<<"numb1"<<numb1;}
            cout<<numb1<<" mih "<<numb2<<'\n';
            lineSum = lineSum + numb1*numb2;
          }
        }
        else if(temp == numb1 && !here){
          numb2 = temp;
        }
      }
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

    int nu = validNums(prevLine, currLine, nextLine);
    // cout<<"pro"<<nu<<'\n';
    GrandTotal = GrandTotal + nu; 

    prevLine = currLine;
    currLine = nextLine;
  }

  cout<<GrandTotal<<'\n';

  inputFile.close();
  return 0;
}

