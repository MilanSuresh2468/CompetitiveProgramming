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
    // a slices of cheese and b slices of sausage.
    // Rules for making sandwiches:
    // -each sandwich must have at least one slice of cheese and one slice of 
    // sausage.
    // -each slice of cheese and slice of sausage must be placed on exactly one sausage.
    // -each sandwich must have more slices of cheese than slices of sausage.
    
    // Example Test Case 1: 
    // a = 6, b = 4. 
    // 2 sandwiches, each with 3 slices of cheese and 2 slices of sausage. 
    
    // a and b are small, so it is possible to verify my solution with
    // bruteforce before submitting. 
    
    int t;
    double a, b;
    cin >> t;
    
    while (t--) {
        cin >> a >> b;
        if (b >= a) {
            cout << -1 << endl;
        } else {
            cout << min(a - b, b) << endl;
        }
    }
    return 0;
}
