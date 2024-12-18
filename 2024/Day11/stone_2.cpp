#include <bits/stdc++.h>

using namespace std;

int BLINKS=44;
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

vector<unsigned long long> getBlink(vector<unsigned long long> initial, unordered_map<int,int> &memorize_2024, unordered_map<int,pair<int,int>> &memorize_split){
    vector<unsigned long long> result;

    for(int i=0; i<initial.size(); i++){
        if(initial[i] == 0){
            result.push_back(1);
            continue;
        }
        
        pair<bool,int> divisor = numDivisor(initial[i]);
        if(divisor.first){
            if(memorize_split.count(initial[i]) == 0){
                memorize_split[initial[i]] = make_pair(initial[i]/divisor.second, initial[i]%divisor.second);
            }
            result.push_back(memorize_split[initial[i]].first);
            result.push_back(memorize_split[initial[i]].second);
        }
        else {
            if(memorize_2024.count(initial[i]) == 0){
                memorize_2024[initial[i]] = initial[i]*2024;
            }
            result.push_back(memorize_2024[initial[i]]);
        }
    }
    return result;
}

int main(){
    vector<unsigned long long> initial = {125, 17};

    unordered_map<int,int> memorize_2024;
    unordered_map<int,pair<int,int>> memorize_split;

//    int GrandTotal = 0;
//    for(int i=0; i<initial.size(); i++){
//        vector<unsigned long long> single;
//        single.push_back(initial[i]);

        for(int j=0; j<BLINKS; j++){
            initial = getBlink(initial, memorize_2024, memorize_split);
        }
//        GrandTotal += single.size();
//    }
//
//    cout<<GrandTotal<<endl;
    cout<<initial.size()<<endl;
}
