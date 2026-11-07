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
    // Binary string s of even length n. 
    // A pair of indices (i, n - i + 1) is good if s_i = s_{n-i+1}.
    // Is it possible to rearrange s, so that there are k good pairs?
    // 1 ≤ t ≤ 10^4.
    // Each test case:
    // n k (2 ≤ n ≤ 2*10^5, 0 ≤ k ≤ n/2, n is even)
    // s
    // Output "YES" or "NO" for each test case.
    
    // Test Case 1: 
    // n = 6, k = 2.
    // s = "000000". 
    // There are three good pairs no matter what.
    // "NO"
    
    // Test Case 2:
    // n = 2, k = 1.
    // s = "01".
    // There are 0 good pairs no matter what. 
    // "NO"
    
    // Test Case 3:
    // n = 4, k = 1.
    // s = "1011".
    // If we keep the string as is, there is one good pair.
    // "YES".
    
    // Test Case 4:
    // n = 10, k = 2.
    // s = "1101011001".
    // There are 6 1's and 4 0's. 
    // There are two 1's that must always get paired together.
    // W.L.O.G., say we pair 2 more 1's together. Then we have 2 1's and 4 0's.
    // There are more 0's than 1's, so we must make a third good pair.
    // We therefore have three good pairs, which is too many.
    // "NO".
    
    // Test Case 5:
    // n = 10, k = 1.
    // s = "1101011001".
    // There are 6 1's and 4 0's.
    // We can pair 2 1's together.
    // Make 4 pairs of 0/1. 
    // s' = "1111110000".
    // "YES".
    
    // Test Case 6:
    // n = 2, k = 1.
    // s = "11".
    // s has 1 good pair.
    // "YES".
    
    // countOnes: number of 1's. countZeros: number of 0's. 
    // We will always have (|countOnes - countZeros)/2 good pairs. 
    // This leaves us with min(countOnes, countZeros). 
    // We can make 0,2,...,2*floor(min(countOnes,countZeros)/2) good pairs. 
    
    // minGood = |countOnes - countZeros|/2.
    // maxGood = minGood + 2*(min(countOnes, countZeros)/2).
    // Possible values: minGood, minGood + 2,...,maxGood.
    
    int t, n, k, countOnes, countZeros, minGood, maxGood;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> s;
        countZeros = 0;
        countOnes = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') countZeros++;
            else countOnes++;
        }
        
        minGood = abs(countOnes - countZeros)/2;
        maxGood = minGood + 2*(min(countOnes, countZeros)/2);
        
        // Is k in {minGood, minGood+2,...,maxGood}?
        if (k >= minGood && k <= maxGood && (k-minGood)%2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
