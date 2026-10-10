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
    int n; 
    cin >> n;
    
    cout << n/2 << endl;
    
    if (n%2 == 1) {
        cout << "3 "; 
        n -= 3;
    }
    
    for (int i = 0; i < n/2; i++) {
        cout << "2 ";
    }
    
    
    return 0;
}
