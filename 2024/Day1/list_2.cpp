#include <bits/stdc++.h>

using namespace std;

void insertLocations(string line, unordered_map<int,int> &left, unordered_map<int,int> &right){

    int leftNum, rightNum;
    string l, r;
    istringstream iss(line);

    if(iss >> l >> r){
        leftNum = stoi(l);
        rightNum = stoi(r);
    }

    left[leftNum]++;
    right[rightNum]++;
}

int main(){

    ifstream inputFile;
    inputFile.open("./list_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    unordered_map<int, int> left, right; 

    string line;
    while(getline(inputFile, line)){
        insertLocations(line, left, right);
    }

    int GrandTotal = 0;
    for (const auto& [key, value] : left) {
        GrandTotal += key * right[key] * left[key];
    }
    cout<<GrandTotal<<endl;
    return 0;
}

