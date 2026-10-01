#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
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
    // Hamed starts with 1 dollar.
    // Every day, his balance doubles in the morning.
    // Every night, he may choose to withdraw his balance. If he does so,
    // it resets to 1 dollar.
    // The bank is open for exactly n days. 
    // He wants to withdraw money on exactly k different days before the bank
    // closes. Determine the maximum amount of money that can be on Hamed's
    // card after the n-th day.
    
    // 2^(n + 1 - k) + 2(k - 1) 
    
    long long t, n, k;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        cout << intPow(2, n + 1 - k) + 2*(k - 1) << endl;
    }
    
    return 0;
}
