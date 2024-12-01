#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string PATH = "./camel_cards.txt";
int RANKS = 1000;

class hand{
  public:
    string cards = "";
    int rank = 0; 
    int type = 0;
    int type_new = 0;
    bool conv = false;
    
    hand(){
      cards = "";
      rank = 0;
      type = 0;
      conv = false;
    }
    hand(string cards){

      this->cards = cards;
      int arr[] = {0, 0, 0, 0, 0};
      char ch[5] = {cards[0], ' ', ' ', ' ', ' '};
      int stp = 1;
      for(int i=0; i<5; i++){
        bool found = false;
        for(int j=0; j<stp; j++){
          if(cards[i] == ch[j]){
            arr[j]++;  
            found = true;
          }  
        }
        if(!found){
          ch[stp] = cards[i];
          arr[stp]++;
          stp++;
        }
      }
      if(arr[0] == 5){
        type = 7;
      }
      else if(arr[0]+arr[1] == 5){
        type = (arr[0]==4 || arr[0]==1) ? 6 : 5;
      }
      else if(arr[4] != 0){
        type = 1;  
      }
      else if(arr[4]==0 && arr[3]!=0){
        type = 2;  
      }
      else{
        type = (arr[0]==3) ? 4 : (arr[0]==2) ? 3 : (arr[1]==2 ? 3 : 4);  
      }
      int Js = 0;
      for(int i=0; i<5; i++){
        if(cards[i] == 'J'){Js++;}
      }
      if(Js == 1){
        switch(type){
          case 1: type_new = 2;
          case 2: type_new = 4;
          case 3: type_new = 5;
          case 4: type_new = 6;
          case 6: type_new = 7;
        }
        conv = true;
      }
      else if((Js == 2 || Js == 3) && type == 5){
        type_new = 7;
        conv = true;
      }
    }
};

int getNum(char ch){
  if(isdigit(ch)){
    return ch-'0';
  }
  switch(ch) {
    case 'A': return 14;
    case 'K': return 13;
    case 'Q': return 12;
    case 'J': return 1;
    case 'T': return 10;
  }
  return 0;
}

bool isHigher(hand hnd1, hand hnd2){
  if(hnd1.type > hnd2.type){
    return true;
  }
  else if(hnd1.type < hnd2.type){
    return false;
  }
  else{
    for(int i=0; i<5; i++){
      int num1 = getNum(hnd1.cards[i]);
      int num2 = getNum(hnd2.cards[i]);
      if(num1 > num2){
        return true;
      }
      else if(num1 < num2){
        return false;
      }
    }
  }
  return false;
}

void getHands(hand* hands_array){

  ifstream inputFile;
  inputFile.open(PATH);

  if(!inputFile.is_open()){
    return;
  }
  
  int GrandTotal = 0;
  string line;
  int start = 1;
  while(getline(inputFile, line)){
    string s;
    istringstream iss(line);
    if(iss >> s){
      hand hnd(s);
      int temp = start;
      for(int i=start-2; i>=0; i--){
        if(isHigher(hnd, hands_array[i])){
          hands_array[i].rank = hands_array[i].rank+1;
          temp--;
        }
      }
      hnd.rank = temp;
      hands_array[start-1] = hnd;
      start++;
    }
  }

  inputFile.close();
}

int main(){
  
  hand hands_array[RANKS];

  getHands(hands_array);

  ifstream inputFile;
  inputFile.open(PATH);

  if(!inputFile.is_open()){
    return 1;
  }
  
  int GrandTotal = 0;
  string line;
  int indx = 0;
  while(getline(inputFile, line)){
    int p;
    string s;
    istringstream iss(line);
    if(iss >> s >> p){
      hand hnd(s);
      cout<<hands_array[indx].cards<<" "<<hands_array[indx].rank<<" \n";
      GrandTotal = GrandTotal + (RANKS+1-hands_array[indx].rank)*p;
      indx++;
    }
  }

  inputFile.close();

  cout<<GrandTotal<<'\n';
  return 0;
}
