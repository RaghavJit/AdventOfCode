#include <bits/stdc++.h>

using namespace std;

void insertRule(string rule, unordered_map<int, unordered_set<int>> &after){
    int left = stoi(rule.substr(0,2)); 
    int right = stoi(rule.substr(3));

    after[left].insert(right);
}

int checkUpdate(string update, unordered_map<int, unordered_set<int>> &after){
    stringstream ss(update);

    vector<int> pages;
    string page;
    while(getline(ss, page, ',')){
        pages.push_back(stoi(page));
        for(int i=0; i<pages.size()-1; i++){
            if(after[pages[i]].count(pages.back()) == 0){
                return 0;
            }
        }
    }

    return pages[pages.size()/2];
}

int main(){
    fstream rules("./rules_input.txt");

    if(!rules.is_open()){
        return 1;
    }

    unordered_map<int, unordered_set<int>> after;

    string rule;
    while (getline(rules, rule)) {
        insertRule(rule, after);
    }

    rules.close();

    fstream updates("./updates_input.txt");

    if(!updates.is_open()){
        return 1;
    }

    int GrandTotal = 0;
    string update;
    while(getline(updates, update)) {
        GrandTotal += checkUpdate(update, after);
    }

    cout<<GrandTotal<<endl;

    return 0;
}