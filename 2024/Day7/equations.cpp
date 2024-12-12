#include <bits/stdc++.h>

using namespace std;

int checkEquation(deque<unsigned long long> nums, unsigned long long target){
    
    if(nums.size() == 1 && nums[0] != target){
        return false;
    }
    if(nums.back() > target){
        return false;
    }

    unsigned long long end = nums.back();
    nums.pop_back();
    unsigned long long new_end = nums.back();

    if(nums.back() == target && ((end*new_end == target) || (end+new_end == target))){
        return true;
    }
     
    deque<unsigned long long> nums_add = nums;
    deque<unsigned long long> nums_mul = nums;

    nums_add.back() += end;
    nums_mul.back() *= end;

    return checkEquation(nums_add, target) || checkEquation(nums_mul, target);
}

unsigned long long readEquation(string line){
    istringstream iss(line);

    string temp;
    iss>>temp;
    unsigned long long target = stoull(temp.substr(0, temp.size()-1));
    deque<unsigned long long> nums;

    while(iss>>temp){
        nums.push_front(stoull(temp));
    }

    if(checkEquation(nums, target)){
        return target;
    }
    return 0;
}

int main(){

    ifstream inputFile;
    inputFile.open("./equations_input.txt");

    if(!inputFile.is_open()){
        return 1;
    }


    string line;

    unsigned long long GrandTotal = 0;
    while(getline(inputFile, line)){
        GrandTotal += readEquation(line);
    }

    cout<<GrandTotal<<endl;
    return 0;
}
