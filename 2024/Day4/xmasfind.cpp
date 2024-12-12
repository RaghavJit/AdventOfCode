#include <bits/stdc++.h>
using namespace std;

int FILE_SIZE = 140;

int searchCount(string line){
    regex pattern(R"(XMAS)");  

    smatch matches;  
    string::const_iterator searchStart(line.cbegin());
    
    int count = 0;

    while (regex_search(searchStart, line.cend(), matches, pattern)) {
        count++;
        searchStart = matches.suffix().first;  
    }

    regex pattern2(R"(SAMX)");  

    smatch matches2;  
    string::const_iterator searchStart2(line.cbegin());
    
    while (regex_search(searchStart2, line.cend(), matches2, pattern2)) {
        count++;
        searchStart2 = matches2.suffix().first;  
    }
    return count;
}

int scanHorizontal(vector<string>& lines){
    int count=0;
    for(string line : lines){
        count += searchCount(line);
    }
    return count;
}

int scanVertical(vector<string>& lines){
    int count=0;
    
    for(int i=0; i<FILE_SIZE; i++){
        string line="";
        for(int j=0; j<FILE_SIZE; j++){
             line+=lines[j][i];
        }
        count+=searchCount(line);
    }

    return count;
}

int scanSkewL(vector<string>& lines){
    int count=0;

    for(int k=0; k<FILE_SIZE; k++){
        int i=k, j=0;
        string line="";
        for(int l=0; l<k+1; l++){
            line+=lines[i][j];
            i--;j++;
        }
        count+=searchCount(line);
    }

    for(int k=FILE_SIZE-1; k>0; k--){
        int i=FILE_SIZE-1, j=FILE_SIZE-k;
        string line="";
        for(int l=0; l<k; l++){
            line+=lines[i][j];
            i--;j++;
        }
        count+=searchCount(line);
    }

    return count;
}

int scanSkewR(vector<string>& lines){
    int count=0;

    for(int k=0; k<FILE_SIZE; k++){
        int i=k, j=FILE_SIZE-1;
        string line="";
        for(int l=0; l<k+1; l++){
            line+=lines[i][j];
            i--;j--;
        }
        count+=searchCount(line);
    }

    for(int k=FILE_SIZE-1; k>0; k--){
        int i=FILE_SIZE-1, j=k-1;
        string line="";
        for(int l=0; l<k; l++){
            line+=lines[i][j];
            i--;j--;
        }
        count+=searchCount(line);
    }

    return count;
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

    cout<<
        scanHorizontal(lines)+
        scanVertical(lines)+
        scanSkewL(lines)+
        scanSkewR(lines)<<endl;
    return 0;
}
