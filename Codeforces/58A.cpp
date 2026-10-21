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
    string s;
    bool hasH = false, hasE = false, hasL1 = false, hasL2 = false, hasO = false;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (!hasH) {
            if (s[i] == 'h') hasH = true;
        } else if (!hasE) {
            if (s[i] == 'e') hasE = true;
        } else if (!hasL1) {
            if (s[i] == 'l') hasL1 = true;
        } else if (!hasL2) {
            if (s[i] == 'l') hasL2 = true;
        } else {
            if (s[i] == 'o') hasO = true;
        }
    }
    
    if (hasH && hasE && hasL1 && hasL2 && hasO) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
