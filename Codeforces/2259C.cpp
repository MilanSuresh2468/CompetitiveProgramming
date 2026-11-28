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
    // The score of an array b of length m is the max length of a subarray of b 
    // where the first and last elements are 1, and the other elements are 0.
    // If there is no subarray meeting the requirements, the score of b is 0.
    // You are given an array a_1, a_2,...,a)n such that each element is -1, 0, or 1. Replace 
    // each -1 with a 0 or 1 such that the score of a is maximal over all possible ways to 
    // replace the -1's in a.
    
    // Test Case 1: a = [1,0,-1,0,0,1].
    // I should replace a_3 with 0 to produce a score of 6.
    
    // Test Case 2: a = [0,-1,0,0,1,0,1].
    // I should replace a_2 with 1 to produce a score of 4.
    
    // Test Case 3: a = [-1,0,0,-1,0].
    // I should replace a_1 and a_4 with 1 to produce a score of 4. 
    
    // Test Case 4: a = [0,0,0,0].
    // There are no -1's to replace with a 0 or 1.
    
    // Test Case 5: a = [-1].
    // I should replace a_1 with 1. The largest subarray that satisfies the conditions in the 
    // statement is the full array. 
    
    // Test Case 6: a = [1,0,1,0,0,-1].
    // I should replace a_6 with 1. The largest subarray that satisfies the conditions in the 
    // statement is the array from index 2 to index 4. 
    
    // Test Case 7: a = [0,1,0,0,0,1,0].
    // There are no -1's to replace.
    
    // Test Case 8: a = [-1,-1,-1,-1,-1,-1] -> [1,0,0,0,0,1].
    // The score is 6.
    
    // Test Case 9: a = [-1,0,1,-1,0,0,1]. I should replace a_4 with 1. I can replace a_1 with 
    // 0 or 1. Either value would not create a subarray of length 5 or more satisfying the conditions
    // in the statement and thus would not change the array.
    
    // Test Case 10: a = [-1,0,0]. I should replace a_1 with 1. The subarray only containing a_1 
    // satisfies the conditions in the statement.
    
    // Hint 1: If a -1 is between 2 1's, it would only hurt the answer to make it a 1.
    // Hint 2: If a -1 is not in between two 1's, the -1 would only be included in a subarray 
    // satisfying the conditions if it was an endpoint.
    
    // Official Solution: Set the first and last -1 to 1. Set every other -1 to 0.
    
    int t, n, curr;
    vector <int> a;
    cin.tie(0);
    
    cin >> t;
    
    while (t--) {
        cin >> n;
        a.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.pb(curr);
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) break;
            if (a[i] == -1) {
                a[i] = 1;
                break;
            }
        }
        
        for (int i = n - 1; i > 0; i--) {
            if (a[i] == 1) break;
            if (a[i] == -1) {
                a[i] = 1;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
