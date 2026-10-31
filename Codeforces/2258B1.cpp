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
    // n carrots with sizes a_1,...,a_n.
    // Perform exactly one operation:
    // ->Choose a set of carrots and a positive integer x.
    // ->Cut all carrots with size l > x into two carrots of size x and l - x.
    // Determine the amount of carrots we can make the same size.
    
    // We can always get at least n carrots of the same size (1) by selecting x = 1.
    // Amount of carrots we get by choosing x = #carrots of length x + #carrots of length > x
    // + #carrots of length 2x.
    // We can compute all three of these quantities separately. 
    
    int t, n, m, curr, count, max;
    vector <int> a, ops;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        a.clear();
        ops.clear();
        for (int i = 0; i < n; i++) cin >> curr, a.pb(curr);
        sort(a);
        
        // ops represents the amount of carrots we obtain by performing the operation 
        // with each x from 1 to m.
        ops.assign(m+1, 0);
        
        // Print all the values of ops.
        for (int i = 1; i <= m; i++) {
            //cout << ops[i] << " ";
        }
        //cout << endl;
        
        // Add the #carrots of length x to each value of ops.
        for (int i = 0; i < a.size(); i++) {
            ops[a[i]]++;
        }
        
        // Add the #carrots of length > x to each value of ops.
        count = 0;
        for (int i = m; i >= 1; i--) {
            curr = ops[i];
            ops[i] += count;
            count += curr;
        }
        
        // Add the #carrots of length 2x to each value of ops.
        for (int i = 0; i < a.size(); i++) {
            if (a[i]%2 == 0) {
                ops[a[i]/2]++;
            }
        }
        
        // Find max.
        max = 0;
        for (int i = 1; i <= m; i++) {
            if (ops[i] > max) max = ops[i];
        }
        
        // Print max.
        cout << max << endl;
        
    }
    
    return 0;
}
