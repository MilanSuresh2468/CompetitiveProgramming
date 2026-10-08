#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))
#define erase(x, i) x.erase(x.begin() + i)

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
    // Count how many pairs of non-negative integers (a, b) satisfy the system of
    // equations:
    // {a^2 + b = n
    // {a + b^2 = m.
    
    // Can bruteforce 
    // sqrt(1000) ~ 31.623 
    // Must check 0,1,...,32 for a AND b
    // 32^2 = 1024 possibilities 
    
    int n, m, count = 0; 
    cin >> n >> m;
    
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if ((i*i + j) == n && (i + j*j) == m) {
                count++;
            }
        }
    }
    
    cout << count;
    return 0;
}
