#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string PATH = "./mirage_input.txt";
int LEN = 21;

int calcUp(int* arr, int dpt, int num){
  if(dpt == 1){
    return arr[num];
  }
  return calcUp(arr, dpt-1, num+1) - calcUp(arr, dpt-1, num);
}

int calcDown(int* arr, int dpt, int num){
  int zero = calcUp(arr, dpt, num-1);
  if(zero == 0){
    return 0;
  }
  return calcDown(arr, dpt+1, num-1) + zero; 
}

int newNumber(string line){

  int arr[LEN];

  istringstream iss(line);
  for(int i=0; iss >> arr[i]; i++){};
  
  return calcDown(arr, 1, LEN);
}

int main(){

  fstream inputFile;
  inputFile.open(PATH);

  if(!inputFile.is_open()){
    return 1;
  }

  long int GrandTotal = 0;
  string line;
  while(getline(inputFile, line)){
    GrandTotal = GrandTotal + newNumber(line);
  }

  cout<<GrandTotal<<'\n';
  return 0;
}
