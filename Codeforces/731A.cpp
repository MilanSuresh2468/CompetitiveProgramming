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
    // Find the minimum number of rotations of the wheel required to print a name. Can go clockwise
    // or counterclockwise. 
    // Position 1: a. Position 26: z. 
    // How many rotations is required to get from a to b? min(a - b + 26 mod 26, b - a + 26 mod 26).
    // Do a greedy approach.
    
    cin.tie(0);
    string s; 
    int count = 0;
    cin >> s;
    s = "a" + s;
    
    for (int i = 1; i < s.length(); i++) {
        count += min((s[i] - s[i-1] + 26)%26, (s[i-1] - s[i] + 26)%26);
    }
    
    cout << count;
    
}
