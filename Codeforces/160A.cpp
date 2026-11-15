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
    // There are n coins labelled a_1 thru a_n. 
    // What is the minimum amount of coins you need to take to have a strictly larger amount of money
    // than the other person? 
    
    // Sort the coins and then take the biggest coin until you have strictly more coins. 
    
    cin.tie(0);
    int n, curr, sum1 = 0, sum2 = 0;
    vector <int> a;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> curr;
        a.pb(curr);
        sum1 += curr;
    }
    sort(a);
    
    for (int i = n - 1; i >= 0; i--) {
        sum1 -= a[i];
        sum2 += a[i];
        if (sum2 > sum1) {
            cout << n - i;
            break;
        }
    }
    
    
}
