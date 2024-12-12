#include <bits/stdc++.h>
using namespace std;

int FILE_SIZE = 140;

int checkMas(int i, int j, vector<string> &lines){
    string matchL = "A"; 
    matchL = lines[i-1][j-1]+ matchL +lines[i+1][j+1];

    string matchR = "A"; 
    matchR= lines[i-1][j+1]+ matchR +lines[i+1][j-1];

    if(((matchL == "MAS") || (matchL=="SAM")) && ((matchR=="MAS") || (matchR=="SAM"))){
        return 1;
    }

    return 0;
}

int main() {
    ifstream inputFile("./xmas_input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string line;
    vector<string> lines;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    int GrandTotal=0;
    for(int i=1; i<FILE_SIZE-1; i++){
        for(int j=1; j<FILE_SIZE-1; j++){
            string temp = "";
            temp+=lines[i][j];
            if(temp=="A"){
                GrandTotal+=checkMas(i,j,lines);
            }
        }
    }

    cout<<GrandTotal<<endl;
    return 0;
}
