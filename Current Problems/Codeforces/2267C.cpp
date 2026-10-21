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
    // n piles of coins numbered from 1 to n.
    // The i-th pile has a_i coins. 
    // Dimash uses a number x to steal coins. 
    // Stealing Process:
    // ->Choose index 1 ≤ i ≤ n such that a_i > 0 and gcd(a_i, x) ≠ 1. If there is no such
    // index, the process stops. 
    // ->g = gcd(a_i, x). a_i -= g. 
    // ->x = g. 
    // Find the max number of coins Dimash can steal. 
    
    // Test Case 1: 
    // n = 3, x = 1.
    // a = [2, 3, 5].
    // There is no i such that gcd(a_i, x) ≠ 1, so we cannot ever steal from a pile.
    // 0 coins can be stolen.
    
    // Test Case 2: 
    // n = 3, x = 4.
    // a = [2, 3, 4].
    // Choose pile 3. Take 4 coins. a = [2, 3, 0]. Coins stolen: 4. x = 4. 
    // Choose pile 1. Take 2 coins. a = [0, 3, 0]. Coins stolen: 6. x = 2. 
    // 6 coins can be stolen. 
    
    // Dimash is a greedy pirate, so this is almost certainly a greedy problem.
    
    // Greedy Idea: Steal from the pile with the largest gcd with x.
    
    // Test Case 3: 
    // n = 4, x = 2.
    // a = [2, 2, 2, 2].
    // 
    
    int t, n, x, curr;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        cin >> n >> x;
        a.clear();
        
        for (int i = 0; i < n; i++) cin >> curr, a.pb(curr);
        
        cout << 0 << endl;
        
    }
    return 0;
}
