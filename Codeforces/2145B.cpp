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
    // Monocarp has a deck with cards numbered 1 at the top to n at the bottom.
    // Performed k actions. Each action was one of three types:
    // 1. remove top card 2. remove bottom card 3. remove either top or bottom card
    // determine fate of each card
    
    // k_top = number of times the top card is removed
    // k_bot = number of times the bottom card is removed 
    // k_either = number of times either is removed 
    
    // 1,2,...,k_top are removed
    // k_top+1,k_top+2,...,k_top+k_either might be removed.
    // n-k_bot+1, k_bot+2,...,n are removed.
    // n-k_bot-k_either+1,...,n-k_bot might be removed.
    
    int t, n, k, k_top, k_bot, k_either;
    string s;
    vector<char> result;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> s;
        result.assign(n + 1, '+');
        k_top = 0, k_bot = 0, k_either = 0;
        
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') k_top++;
            else if (s[i] == '1') k_bot++;
            else k_either++;
        }
        // cout << k_top << " " << k_bot << " " << k_either << endl;
        
        // k_top+1,k_top+2,...,k_top+k_either might be removed.
        for (int i = k_top + 1; i <= k_top + k_either; i++) {
            result[i] = '?';
        }
        
        // n-k_bot-k_either+1,...,n-k_bot might be removed.
        for (int i = n - k_bot - k_either + 1; i <= n - k_bot; i++) {
            result[i] = '?';
        }
        
        // 1,2,...,k_top are removed
        for (int i = 1; i <= k_top; i++) {
            result[i] = '-';
        }
        
        // n-k_bot+1, n-k_bot+2,...,n are removed.
        for (int i = n - k_bot + 1; i <= n; i++) {
            result[i] = '-';
        }
        
        // if k >= n, result should be all '-'.
        if (k >= n) result.assign(n + 1, '-');
        
        // Print result
        for (int i = 1; i <= n; i++) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
