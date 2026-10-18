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
    int n, curr, xSum = 0, ySum = 0, zSum = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> curr;
        xSum += curr;
        cin >> curr;
        ySum += curr;
        cin >> curr;
        zSum += curr;
    }
    
    if (xSum == 0 && ySum == 0 && zSum == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
