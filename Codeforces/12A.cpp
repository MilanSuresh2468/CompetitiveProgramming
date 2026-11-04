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
    string s = "";
    char curr;
    
    for (int i = 0; i < 9; i++) {
        cin >> curr;
        s += curr;
    }
    
    for (int i = 0; i < 5; i++) {
        if (s[i] != s[8-i]) {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}
