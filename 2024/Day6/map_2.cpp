#include <bits/stdc++.h>

using namespace std;

int CURSOR_X = 90;
int CURSOR_Y = 66;
int MAP_SIZE = 130;
char START_DIR = 'N';



int main(){
    fstream inputFile("./map_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    string line;
    vector<string> map;
    while(getline(inputFile, line)){
        map.push_back(line);
    }

    int count=0, prev_i=0, prev_j=0;
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            map[i][j] = '#';
            count += traceRoute(map);
        }

    }


    return 0;
}
