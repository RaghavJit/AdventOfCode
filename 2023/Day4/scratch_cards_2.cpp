#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getMatches(string str){
  
  int score = 0;
  int card_numbs[10];

  for(int indx=10; indx<=37; indx+=3){
    int num;
    switch(str[indx]){
      case ' ':
        num = (str[indx+1]-'0');
        break;
      default:
        num = (str[indx]-'0')*10 + (str[indx+1]-'0');
        break;
    }
    card_numbs[(indx-10)/3]=num;
  }
  for(int indx=42; indx<=115; indx+=3){
    int num;
    switch(str[indx]){
      case ' ':
        num = (str[indx+1]-'0');
        break;
      default:
        num = (str[indx]-'0')*10 + (str[indx+1]-'0');
        break;
    }
    for(int i=0; i<10; i++){
      score = (card_numbs[i]==num) ? score+1 : score; 
    }
  }
  return score;
}

string getCard(int number){

  ifstream inputFile;
  inputFile.open("./scratch_cards_input.txt");

  if(!inputFile.is_open()){
    return "";
  }
  
  string line;
  for(int i=0; i<number; i++){
    getline(inputFile, line);
  }

  return line;
}

int getTotalCards(string line, int CardNum){
  int matches = getMatches(line);
  int TotalCards = 1;
  for(int i=CardNum+1; i<=CardNum+matches; i++){
    TotalCards = TotalCards + getTotalCards(getCard(i), i);
  }
  return TotalCards;
}

int main(){

  ifstream inputFile;
  inputFile.open("./scratch_cards_input.txt");

  if(!inputFile.is_open()){
    return 1;
  }
  
  int GrandTotal = 0;
  int CardNum = 1;
  string line;
  while(getline(inputFile, line)){
    cout<<line<<'\n';
    GrandTotal = GrandTotal + getTotalCards(line, CardNum);
    CardNum++;
  }
  inputFile.close();

  cout<<GrandTotal;
  return 0;
}
