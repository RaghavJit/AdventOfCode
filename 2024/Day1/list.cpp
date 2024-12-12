#include <bits/stdc++.h>

using namespace std;

void insertLocations(string line, vector<int> &left, vector<int> &right){
    
    int leftNum, rightNum;
    string l, r;
    istringstream iss(line);

    if(iss >> l >> r){
        leftNum = stoi(l);
        rightNum = stoi(r);
    }

    left.push_back(leftNum);
    right.push_back(rightNum);

    push_heap(left.begin(), left.end());
    push_heap(right.begin(), right.end());
}

int main(){

    ifstream inputFile;
    inputFile.open("./list_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    vector<int> left, right;

    make_heap(left.begin(), left.end());
    make_heap(right.begin(), right.end());

    string line;
    while(getline(inputFile, line)){
        insertLocations(line, left, right);
    }

    inputFile.close();

    sort_heap(left.begin(), left.end());
    sort_heap(right.begin(), right.end());

    int GrandTotal = 0;
    for(int i=0; i<1000; i++){
        GrandTotal += abs(left[i]-right[i]);
    }

    cout<<GrandTotal<<endl;
    return 0;
}

