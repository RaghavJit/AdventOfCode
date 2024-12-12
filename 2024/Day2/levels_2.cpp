#include <bits/stdc++.h>

using namespace std;

int anomalyPresent(int prev, int current, bool increasing){
    int diff = current-prev;
    if((diff>0 && increasing) || (diff<0 && !increasing) || (diff == 0) || (abs(diff) > 3)){
        return true;
    } 
    return false;
}

int getTrend(vector<int> &nums){
    int diffSum = 0;
    for(int i=1; i<nums.size(); i++){
        diffSum += (nums[i-1] - nums[i]);
    }
    return (diffSum>0);
}

int checkReport(vector<int> &nums){

    bool increasing = getTrend(nums);
    bool fixed = false;
    int anomalies = 0;

    for(int i=0; i<nums.size()-1; i++){
        if(anomalyPresent(nums[i], nums[i+1], increasing)){
            if(!fixed && (!anomalyPresent(nums[i-1], nums[i+1], increasing))){
                fixed = true;
                return 1;
            }
            return 0; 
        }
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

    int GrandTotal = 0, num;
    while(getline(inputFile, line)){
        istringstream iss(line);
        vector<int> nums;
        while(iss >> num){
            nums.push_back(num);
        }
        GrandTotal += checkReport(nums);
    }

    cout<<GrandTotal<<endl;
    return 0;
}

