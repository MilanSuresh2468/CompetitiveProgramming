#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))
#define erase(x, i) x.erase(x.begin() + i)
#define pb push_back

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int intPow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // a is a binary array of length n. 
    // A blank space is a segment of consecutive elements consisting of only 0's.
    // Your task is to find the length of the longest blank space.
    // What is the maximum amount of 0's in a row?
    
    int t, n, max, curr, count;
    cin >> t;
    
    while (t--) {
        cin >> n;
        max = 0;
        count = 0;
        
        while (n--) {
            cin >> curr;
            if (curr == 0) {
                count++;
                if (count > max) max = count;
            } else {
                count = 0;
            }
        }
        
        cout << max << endl;
    }
    return 0;
}
