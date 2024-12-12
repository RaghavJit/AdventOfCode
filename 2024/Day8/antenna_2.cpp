#include <bits/stdc++.h>

using namespace std;

int MAP_SIZE=50;

bool insideMap(int x, int y){
    return ((x>=0) && (x<MAP_SIZE) && (y>=0) && (y<MAP_SIZE));
}

void predictAntiNodes(pair<int,int> loc1, pair<int,int> loc2, set<pair<int,int>> &antinodes){
    int x1 = loc1.first;
    int y1 = loc1.second;
    int x2 = loc2.first;
    int y2 = loc2.second;

    int diffx = x2-x1;
    int diffy = y2-y1;

    if(insideMap(x1-diffx, y1-diffy)){
        antinodes.insert(make_pair(x1 - diffx, y1 - diffy));
    }
    if(insideMap(x2+diffx, y2+diffy)){
        antinodes.insert(make_pair(x2 + diffx, y2 + diffy));
    }
}

void scanMap(vector<string> &map, char antenna, set<pair<int,int>> &antinodes){
    set<pair<int,int>> locations;
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            if(map[i][j] == antenna){
                locations.insert({i,j});
            } 
        }
    } // all antenna locations of 'antenna' type

    for (auto it1 = locations.begin(); it1 != locations.end(); ++it1) {
        for (auto it2 = locations.begin(); it2 != it1; ++it2) {
            predictAntiNodes(*it1, *it2, antinodes);
        }
    }
}

int main(){

    ifstream inputFile;
    inputFile.open("./antennas_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }


    string line;
    vector<string> map;
    set<pair<int,int>> antinodes;

    while(getline(inputFile, line)){
        map.push_back(line);
    } // create map

    set<char> antennas;
    for (const auto& row : map) {
        for (char c : row) {
            antennas.insert(c);
        }
    }
    antennas.erase('.');
    // get all antenna types

    for (char antenna : antennas) {
        scanMap(map, antenna, antinodes);
    } // check for each antenna type

    cout<<antinodes.size()<<endl;

    return 0;
}
