#include <bits/stdc++.h>

using namespace std;

int CURSOR_X = 6;
int CURSOR_Y = 4;
int MAP_SIZE = 10;

int lookAhead(int i, int j, char direction, vector<string>& map){
    switch(direction){
        case 'N':
            i--;
            break;
        case 'S':
            i++;
            break;
        case 'E':
            j++;
            break;
        case 'W':
            j--;
            break;
    }

    if((i<=-1) || (i>=MAP_SIZE) || (j<=-1) || (j>=MAP_SIZE)){
        return 1;
    }
    else if(map[i][j] == '#'){
        return 2;
    }

    return 0;
}

int traceRoute(vector<string> &map){
    
    unordered_map<char, char> switch_direction = {
        {'N','E'},
        {'E','S'},
        {'S','W'},
        {'W','N'},
    };

    char direction='N';
    int i=CURSOR_X, j=CURSOR_Y;
    set<pair<int, int>> positions;

    while(true){
        short int status = lookAhead(i, j, direction, map);
        if(status == 2){
            direction = switch_direction[direction];
        }
        else if(status == 1){
            break;
        }
        else {
            map[i][j]='X';
            switch(direction){
                case 'N':
                    i--;
                    break;
                case 'S':
                    i++;
                    break;
                case 'E':
                    j++;
                    break;
                case 'W':
                    j--;
                    break;
            }
            positions.insert({i,j});
        }

    }
    
    return positions.size()+1;
}

int main(){
    fstream inputFile("./test.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    string line;
    vector<string> map;
    while(getline(inputFile, line)){
        map.push_back(line);
    }

    cout<<traceRoute(map);

    for(int i=0; i<map.size(); i++){
        cout<<map[i]<<endl;
    }
    return 0;
}
