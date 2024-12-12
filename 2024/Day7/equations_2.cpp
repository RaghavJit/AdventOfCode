#include <bits/stdc++.h>

using namespace std;

unsigned long long thirdOpt(unsigned long long left, unsigned long long right){
    return stoull(to_string(left) + to_string(right));
}

int checkEquation(deque<unsigned long long> nums, unsigned long long target){
    
    if(nums.size() == 1 && nums[0] != target){
        return false;
    }
    if(nums.front() > target){
        return false;
    }

    unsigned long long front = nums.front();
    nums.pop_front();
    unsigned long long new_front = nums.front();

    if(nums.size() == 1 && ((front*new_front == target) || (front+new_front == target) || (thirdOpt(front, new_front) == target))){
        return true;
    }
     
    deque<unsigned long long> nums_add = nums;
    deque<unsigned long long> nums_mul = nums;
    deque<unsigned long long> nums_opt = nums;

    nums_add.front() = new_front + front;
    nums_mul.front() = new_front * front;
    nums_opt.front() = thirdOpt(front, new_front);

    return checkEquation(nums_add, target) || checkEquation(nums_mul, target) || checkEquation(nums_opt, target);
}

unsigned long long readEquation(string line){
    istringstream iss(line);

    string temp;
    iss>>temp;
    unsigned long long target = stoull(temp.substr(0, temp.size()-1));
    deque<unsigned long long> nums;

    while(iss>>temp){
        nums.push_back(stoull(temp));
    }

    if(checkEquation(nums, target)){
        //cout<<target<<endl;
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
