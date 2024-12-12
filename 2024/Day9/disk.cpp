#include <bits/stdc++.h>

using namespace std;

int LENGTH=20000;

void printVector(const vector<int>& vec) {
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl; // Add a new line after printing all elements
}

void parseString(string input_string, vector<int> &parse_output, vector<int> &space_indexes){
    int disk_id = 0;
    for(int i=0; i<LENGTH-1; i++){
        int input_num = input_string[i]-'0';
        if(i%2==0){
            for(int j=0; j<input_num; j++){
                parse_output.push_back(disk_id);
            }
            disk_id++;
        }
        else {
            space_indexes.push_back(input_num);
        }
    }
}

vector<int> buildCompress(vector<int> &parse_output, vector<int> &space_indexes){
    vector<int> output;
    output.push_back(parse_output[0]);
    int j = 0;
    for(int i=1; i<parse_output.size(); i++){
        if(parse_output[i] == parse_output[i-1]){
            output.push_back(parse_output[i]);
        }
        else {

            for(int k=0; k<space_indexes[j]; k++){
                output.push_back(parse_output.back());
                parse_output.pop_back();
            }
            j++;
            output.push_back(parse_output[i]);
        }
    }

    return output;
}

long getCheckSum(vector<int> input){
    long sum = 0;
    for(int i=0; i<input.size(); i++){
        sum += i * input[i];
    }
    return sum;
}

int main(){

    fstream InputFile("./disk_input.txt");

    string input_string;
    getline(InputFile, input_string);
 
    vector<int> parse_output;
    vector<int> space_indexes;
    parseString(input_string, parse_output, space_indexes);

    vector<int> compress_output = buildCompress(parse_output, space_indexes); 

    cout<<getCheckSum(compress_output)<<endl;

    return 0;
}
