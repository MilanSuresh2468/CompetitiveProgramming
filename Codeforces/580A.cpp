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
bool isPrime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int intPow(ll x, ll y) {
    ll result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // Find the longest non-decreasing subsegment of a. 
    // 1 ≤ n ≤ 10^5.
    // 1 ≤ a_i ≤ 10^9.
    
    // Algorithm: 
    // ->maximum = 1.
    // ->current = 0.
    // Go though every a_i and update current. If current > maximum, maximum = current;
    
    int n, lastElement, currentElement, maximum = 1, current = 1;
    cin >> n; 
    cin >> currentElement;
    
    while (--n) {
        lastElement = currentElement;
        cin >> currentElement;
        
        if (currentElement >= lastElement) {
            current++;
            if (current > maximum) maximum = current;
        } else {
            current = 1;
        }
    }
    
    cout << maximum;
    cin.tie(0);
}
