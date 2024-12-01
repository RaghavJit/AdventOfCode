#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PATH = "./pipe_maze_input.txt";
int SIZE_X = 140;
int SIZE_Y = 140;
int S_X = 38;
int S_Y = 55;

class cords{
public:
  int X, Y;
  cords(int X=0, int Y=0){
    this->X = X;
    this->Y = Y;
  }
  cords at(char D){

    int x=this->X;
    int y=this->Y;

    switch(D){
      case 'N': x--; break;
      case 'S': x++; break;
      case 'W': y--; break;
      case 'E': y++; break;
    }

    return cords(x, y);
  }

  bool operator ==(cords &C){
    return (C.X == X) && (C.Y == Y);
  }
};

cords searchCords(char (*arr)[140], cords prev, cords serc){

  switch(arr[serc.X][serc.Y]){
    case '|':
      return (serc.at('N') == prev) ? serc.at('S') : serc.at('N');
    case '-':
      return (serc.at('W') == prev) ? serc.at('E') : serc.at('W');
    case 'F':
      return (serc.at('E') == prev) ? serc.at('S') : serc.at('E');
    case 'L':
      return (serc.at('N') == prev) ? serc.at('E') : serc.at('N');
    case '7':
      return (serc.at('W') == prev) ? serc.at('S') : serc.at('W');
    case 'J':
      return (serc.at('N') == prev) ? serc.at('W') : serc.at('N');
  }

  return cords(0, 0);
}

int main(){

  char arr[SIZE_X][140];

  ifstream inputFile;
  inputFile.open(PATH);

  if(!inputFile.is_open()){
    return 1;
  }

  string line;
  for(int lineNum=0; getline(inputFile, line); lineNum++){
    for(int charNum=0; charNum<SIZE_Y; charNum++){
      arr[lineNum][charNum] = line[charNum];
    }
  }

  cords currC(S_X-1, S_Y);
  cords prevC(S_X, S_Y);
  int steps = 1;
  while(true){ 
    if(arr[currC.X][currC.Y]=='S'){
      break;
    }
    int x = currC.X; int y = currC.Y;
    currC = searchCords(arr, prevC, currC);
    prevC.X = x; prevC.Y = y;
    steps++;
  }

  cout<<steps/2<<'\n';
  return 0;
}
