#include <bits/stdc++.h>

using namespace std;

int BLINKS=30;
void printVector(const std::vector<unsigned long long> vec) {
    for (unsigned long long elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
pair<bool, int> numDivisor(unsigned long long x) {
    if (x == 0) return make_pair(false, 1);
    if (x >= 1000000000000000000LL) return make_pair(false, 1);
    if (x >= 100000000000000000LL) return make_pair(true, 1000000000);
    if (x >= 10000000000000000LL) return make_pair(false, 1);
    if (x >= 1000000000000000LL) return make_pair(true, 100000000);
    if (x >= 100000000000000LL) return make_pair(false, 1);
    if (x >= 10000000000000LL) return make_pair(true, 10000000);
    if (x >= 1000000000000LL) return make_pair(false, 1);
    if (x >= 100000000000LL) return make_pair(true, 1000000);
    if (x >= 10000000000LL) return make_pair(false, 1);
    if (x >= 1000000000LL) return make_pair(true, 100000);
    if (x >= 100000000LL) return make_pair(false, 1);
    if (x >= 10000000LL) return make_pair(true, 10000);
    if (x >= 1000000LL) return make_pair(false, 1);
    if (x >= 100000LL) return make_pair(true, 1000);
    if (x >= 10000LL) return make_pair(false, 1);
    if (x >= 1000LL) return make_pair(true, 100);
    if (x >= 100LL) return make_pair(false, 1);
    if (x >= 10LL) return make_pair(true, 10);
    return make_pair(false, 1);
}

vector<unsigned long long> getBlink(vector<unsigned long long> initial){
    vector<unsigned long long> result;

    for(int i=0; i<initial.size(); i++){
        if(initial[i] == 0){
            result.push_back(1);
            continue;
        }
        
        pair<bool,int> divisor = numDivisor(initial[i]);
        if(divisor.first){
            result.push_back(initial[i]/divisor.second);
            result.push_back(initial[i]%divisor.second);
        }
        else {
            result.push_back(initial[i]*2024);
        }
    }
    return result;
}

int main(){
    vector<unsigned long long> initial = {125, 17};

    unordered_map<int,int> memorize_2024;
    unordered_map<int,pair<int,int>> memorize_split;

    for(int i=0; i<BLINKS; i++){
        initial = getBlink(initial);
        //printVector(initial);
    }
    cout<<initial.size()<<endl;
}
