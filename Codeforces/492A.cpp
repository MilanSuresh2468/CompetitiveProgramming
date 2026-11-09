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
    // 1, 3, 6, 10 
    //  2  3   4 
    //    1  1 
    // Since the differences between adjacent elements changes by a constant factor, the 
    // relationship between level of cube and number of cubes is quadratic.
    
    int n, max = 1, runningTotal = 1, currentLevel = 1;
    cin >> n;
    
    for (int i = 2; i <= 1000; i++) {
        currentLevel += i;
        runningTotal += currentLevel;
        if (runningTotal <= n) max++;
        else break;
    } 
    
    cout << max;
}
