#include <bits/stdc++.h>

using namespace std;

int MAP_SIZE=140;

bool insideMap(int x, int y){
    return ((x>=0) && (x<MAP_SIZE) && (y>=0) && (y<MAP_SIZE));
}

void getArea(int i, int j, char crop, std::set<std::pair<int, int>> &area, std::vector<std::vector<char>> &map) {
    if (!insideMap(i, j) || map[i][j] != crop || area.count({i, j}) > 0) {
        return;
    }

    area.insert({i, j});

    getArea(i - 1, j, crop, area, map); 
    getArea(i + 1, j, crop, area, map); 
    getArea(i, j - 1, crop, area, map);
    getArea(i, j + 1, crop, area, map);
}

int getParam(char crop, set<pair<int,int>> &area, vector<vector<char>> &map){
    int total = 0;
    for(pair block: area){
        int max = 4;
        if(insideMap(block.first-1, block.second) && map[block.first-1][block.second] == crop){max--;}
        if(insideMap(block.first+1, block.second) && map[block.first+1][block.second] == crop){max--;}
        if(insideMap(block.first, block.second-1) && map[block.first][block.second-1] == crop){max--;}
        if(insideMap(block.first, block.second+1) && map[block.first][block.second+1] == crop){max--;}
        total+=max;
    }
    return total;
}

int getCost(vector<vector<char>> &map, char crop){
    int total = 0;
    set<pair<int,int>> visited;

    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            if(map[i][j] == crop && visited.count(make_pair(i,j)) == 0){
                set<pair<int,int>> area;
                getArea(i, j, crop, area, map);
                int param = getParam(crop, area, map);
                //cout<<crop<<" "<<area.size()<<" "<<param<<endl;
                total += area.size() * param;

                visited.insert(area.begin(), area.end());
            }
        }
    }

    return total;
}

int main(){

    ifstream inputFile;
    inputFile.open("./garden_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }


    string line;
    vector<vector<char>> map;
    set<char> crop_types;

    while(getline(inputFile, line)){
        vector<char> row;
        for (char c : line) {
            row.push_back(c); 
        }
        map.push_back(row);
    } // create map

    for (const auto& row : map) {
        for (char c : row) {
            crop_types.insert(c);
        }
    }
    // get all crop types

    int GrandTotal = 0;
    for (char crop : crop_types) {
        int temp = getCost(map, crop);
        GrandTotal += temp;
    } // check for each crop type

    cout<<GrandTotal<<endl;

    return 0;
}
