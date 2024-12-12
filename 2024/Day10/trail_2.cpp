#include <bits/stdc++.h>

using namespace std;

int MAP_SIZE=47;

bool insideMap(int x, int y){
    return ((x>=0) && (x<MAP_SIZE) && (y>=0) && (y<MAP_SIZE));
}

void exploreTrail(int i, int j, int step, set<pair<int,int>> &peaks_reached, vector<vector<int>> map){
    if(map[i][j] == 9 && step == 9){
        peaks_reached.insert(make_pair(i,j));
        return;
    }
    if(map[i][j] != step){
        return;    
    }

    if(insideMap(i-1, j) && map[i-1][j] == step+1){exploreTrail(i-1, j, step+1, peaks_reached, map);}
    if(insideMap(i+1, j) && map[i+1][j] == step+1){exploreTrail(i+1, j, step+1, peaks_reached, map);}
    if(insideMap(i, j-1) && map[i][j-1] == step+1){exploreTrail(i, j-1, step+1, peaks_reached, map);}
    if(insideMap(i, j+1) && map[i][j+1] == step+1){exploreTrail(i, j+1, step+1, peaks_reached, map);}
}

int getTrails(vector<vector<int>> map, int i, int j){
    if(map[i][j] != 0){
        return 0;
    }


    set<pair<int,int>> peaks_reached;
    exploreTrail(i, j, 0, peaks_reached, map);

    return peaks_reached.size();
}

int main(){

    ifstream inputFile;
    inputFile.open("./trail_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    string line;
    vector<vector<int>> map;
    while (getline(inputFile, line)) {
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0'); 
        }
        map.push_back(row);
    } // build map
    inputFile.close();

    int GrandTotal = 0;
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            GrandTotal += getTrails(map, i, j);
        }
    }

    cout<<GrandTotal<<endl;
    return 0;
}
