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
    // a_1, a_2,... ,a_n represent points on a number line. 
    // Token initially at coordinate 0.
    // Reflecting the token about a point moves it to the other side of a point.
    // Choose integer p. Paco's token gets reflected about p, a_1, a_2,..., a_n, in this
    // order. 
    // Help Paco find p such that his token ends at 0. 
    
    // Does order matter? 
    // 3 1 vs. 1 3.
    // 0 -> 6 -> -4.
    // 0 -> 2 -> 4.
    // Yes, the order of the reflections matters.
    
    // Test Case 1: a = [3]. Choose p = 3.
    // 0 -> 6 -> 0.
    
    // Test Case 2: a = [2, 5]. Choose p = -3. 
    // 0 -> -6 -> 10 -> 0.
    
    // Test Case 3: a = [2, 7, 1]. Choose p = -4. 
    // 0 -> -8 -> 12 -> 2 -> 0.
    
    // Test Case 4: a = [-3, 0, -3, 0]. Choose p = -6. 
    // 0 -> -12 -> 6 -> -6 -> 0 -> 0.
    
    // Test Case 5: a = [0]. Choose p = 0. 
    // 0 -> 0 -> 0. 
    
    // Want the token to be at 2*a_n before a_n.
    
    // If a is one-long, then choose p = a_1. 
    // If a is two-long, then choose p = a{n-1} - a_n. 
    // Repeat recurrence.
    
    ll t, n, curr;
    vector<int> a;
    
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); 
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.push_back(curr);
        }
        
        curr = a[n-1];
        
        for (int i = n - 2;i >= 0; i--) {
            curr = a[i] - curr;
        }
        
        cout << curr << endl;
        
    }
    return 0;
}
