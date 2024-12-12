#include <bits/stdc++.h>

using namespace std;

int checkReport(string line){
    istringstream iss(line);

    int trend=0;
    int current, prev;
    iss>>current;
    prev=current;

    while(iss>>current){
        int diff = current-prev;
        if(trend == 0){
            trend = (diff>0) ? 1 : -1; 
        }
        if((diff>0 && trend==-1) || (diff<0 && trend==1) || (diff == 0) || (abs(diff) > 3)){
            return 0;
        }
        prev=current;
    }
    return 1;
}

int main(){

    ifstream inputFile;
    inputFile.open("./levels_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }


    string line;

    int GrandTotal = 0;
    while(getline(inputFile, line)){
        GrandTotal += checkReport(line);
    }

    cout<<GrandTotal<<endl;
    return 0;
}

