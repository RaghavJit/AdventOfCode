#include <bits/stdc++.h>

using namespace std;

int LENGTH=20;

void printVector(const vector<string>& vec) {
    for (string elem : vec) {
        cout << elem << " ";
    }
    cout << endl; // Add a new line after printing all elements
}

void parseString(string input_string, vector<string> &parse_output){
    int disk_id = 0;
    for(int i=0; i<LENGTH-1; i++){
        int input_num = input_string[i]-'0';
        if(i%2==0){
            for(int j=0; j<input_num; j++){
                parse_output.push_back(to_string(disk_id));
            }
            disk_id++;
        }
        else {
            for(int j=0; j<input_num; j++){
                parse_output.push_back(".");
            }
        }
    }
    printVector(parse_output);
}

void buildCompress(vector<string> &parse_output){
    int forward = 0;
    int backward = LENGTH-1;

    while(true){
        
    }
}

long getCheckSum(vector<int> input){
    long sum = 0;
    for(int i=0; i<input.size(); i++){
        sum += i * input[i];
    }
    return sum;
}

int main(){

    fstream InputFile("./test.txt");

    string input_string;
    getline(InputFile, input_string);
 
    vector<string> parse_output;
    parseString(input_string, parse_output);

//    cout<<getCheckSum(compress_output)<<endl;

    return 0;
}
