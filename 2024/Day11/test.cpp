#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

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

int main() {
    while(true){
        unsigned long long input;
        cin>>input;
        pair<bool, unsigned long long> divisor = numDivisor(input);

        if (divisor.first) {
            unsigned long long part1 = input / divisor.second;
            unsigned long long part2 = input % divisor.second;
            cout << "Divided parts: " << part1 << " and " << part2 << endl;
        } else {
            cout << "Number does not have an even number of digits." << endl;
        }
    }
    

    return 0;
}

