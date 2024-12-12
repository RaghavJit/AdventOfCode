#include <bits/stdc++.h>

using namespace std;

int product(string str){
    int result = 1;

    regex pattern(R"(\d{1,3})");  

    smatch nums;  
    string::const_iterator searchStart(str.cbegin());
    
    while (regex_search(searchStart, str.cend(), nums, pattern)) {
        result *= stoi(nums[0]);
        cout<<nums[0];
        searchStart = nums.suffix().first;  
    }
    cout<<endl;

    return result;
}

int shouldMultiply(size_t index, string line){
    string str1 = "do()";
    string str2 = "don't()";
    int j1=3, j2=6;

    for(long i=index; i>0; i--){
        if(line[i] == str1[j1]){
            j1--;
        } 
        else{
            j1=3;
        }
        if(line[i] == str2[j2]){
            j2--;
        } 
        else{
            j2=6;
        }

        if(j1==-1){
            return true;
        }
        if(j2==-1){
            return false;
        }
    }
    return true;
}

int getProds(string line){
    regex pattern(R"(mul\([0-9]{1,3},[0-9]{1,3}\))");  

    smatch matches;  
    string::const_iterator searchStart(line.cbegin());
    
    int lineSum = 0;

    while (regex_search(searchStart, line.cend(), matches, pattern)) {
        size_t index = distance(line.cbegin(), matches[0].first);
        if(shouldMultiply(index, line)){
            cout<<matches[0]<<endl;
            lineSum += product(matches[0].str());        
        }
        searchStart = matches.suffix().first;  
    }

    return lineSum;
}
 
int main(){
    ifstream inputFile;
    inputFile.open("./memory_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }

    int GrandTotal=0;
    string line;
    while(getline(inputFile, line)){
        GrandTotal += getProds(line);
    }
    cout<<GrandTotal<<endl;

    return 0;
}
