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
    // s is a binary string of length n. k is an integer.
    // Aquawave wants to construct a permutation p of length n, so that for each 1 ≤ i ≤ n,
    // where s_i = 1, the following holds:
    // ->For each interval [l, r] with length ≥ k, if it covers position i, then the
    // maximum element among p_l,p_{l+1},...,p_r is *not* p_i.
    // You have to find such a permutation, or determine that such permutations do not 
    // exist. 
    
    // In other words, find a permutation of length n where no interval of at least k has
    // a max at an index i where s_i = 1.
    
    // If there s has k 1's in a row, then we cannot form a valid permutation because 
    // if p_i is the max of p_l,...,p_r, s_i must equal 1.
    
    // Test Case 1: n = 2, k = 1, s = "00".
    // p = [1,2]. No s_i = 1, so all intervals are valid. Thus, p works. 
    
    // Test Case 2: n = 4, k = 3, s = "0010".
    // p = [2,3,1,4]. If an interval has at least three elements, one of them must be 3 
    // or 4 => p_3 cannot be the max => the interval is valid => p works.
    
    // Test Case 3: n = 5, k = 2, s = "11011".
    // No. We can select the interval [1,2] for any permutation. [1,2] is never valid 
    // since either p_1 must be the max (s_1 = 1), or p_2 must be the max (s_2 = 1).
    
    // Test Case 4: n = 7, k = 5, s = "1111110". 
    // No. We can select the interval [1,5] for any permutation. [1,5] is never valid.
    
    // Theory: We answer no if there are k 1's in a row. If there are not k 1's in a row,
    // we fill in the biggest numbers at positions i where s_i = 0 from left to right
    // and then fill in the 0's.
    
    int t, n, k, consecutiveOnes;
    bool flag;
    string s;
    vector <int> p;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> s;
        p.assign(n, 0);
        flag = false;
        
        
        // Are there k consecutive 1's?
        consecutiveOnes = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                consecutiveOnes++;
                if (consecutiveOnes >= k) {
                    flag = true;
                }
            } else {
                consecutiveOnes = 0;
            }
        }
        
        // If there are k consecutive 1's, print "NO".
        if (flag) {
            cout << "NO\n";
            continue;
        }
        
        // Otherwise, fill in the indices of p where s_i = 0 starting with the biggest 
        // number. Then fill in the other indices of p. 
        for (int i = 0; i < p.size(); i++) {
            if (s[i] == '0') {
                p[i] = n;
                n--;
            }
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 0) {
                p[i] = n;
                n--;
            }
        }
        
        // Print p. 
        cout << "YES\n";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
