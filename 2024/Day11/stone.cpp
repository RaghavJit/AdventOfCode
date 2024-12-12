#include <bits/stdc++.h>

using namespace std;

int BLINKS=25;

vector<unsigned long long> getBlink(vector<unsigned long long> initial){
    for(int i=0; i<initial.size(); i++){
        unsigned long long temp = initial[i]; 
        string temp_str = to_string(temp);
        if(temp == 0){
            initial[i] = 1;
        }
        else if(temp_str.size()%2 == 0){
            initial[i] = stoull(temp_str.substr(0, temp_str.size()/2));
            initial.insert(initial.begin() + i + 1, stoull(temp_str.substr(temp_str.size()/2)));
            i++;
        }
        else {
            initial[i] = initial[i]*2024;
        }
    }
    return initial;
}

int main(){
    vector<unsigned long long> initial = {17};

    for(int i=0; i<BLINKS; i++){
        initial = getBlink(initial);
    }
    cout<<initial.size()<<endl;
}
