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
    // Permutation p of length n.
    // Perform operation exactly once: choose indices i_1 < i_2 < ... < i_m. Reverse
    // the elements of p at the chosen indices. 
    // Determine whether it is possible to sort p in increasing order. 
    
    // If p_i is in place, then it shouldn't be moved. If p_i isn't in place, it must
    // be moved. 
    // Select a list of indices that are all out of place. 
    
    int t, n, m, curr, element1, element2;
    bool flag;
    vector <int> p, indicesOutOfPlace;
    cin >> t;
    
    while (t--) {
        cin >> n;
        flag = true;
        p.clear(), indicesOutOfPlace.clear();
        while (n--) cin >> curr, p.pb(curr);
        n = p.size();
        
        // Note which indices have elements that are out of place. 
        for (int i = 0; i < p.size(); i++) {
            if (p[i] != (i + 1)) indicesOutOfPlace.pb(i);
        }
        
        // Check if performing the operation with the out of place indices sorts p 
        // in increasing order.
        
        // Do the operation.
        m = indicesOutOfPlace.size();
        for (int j = 0; j < indicesOutOfPlace.size(); j++) {
            if (p[indicesOutOfPlace[j]] == (indicesOutOfPlace[j] + 1)) continue;
            element1 = p[indicesOutOfPlace[j]];
            element2 = p[indicesOutOfPlace[m - j - 1]];
            p[indicesOutOfPlace[j]] = element2;
            p[indicesOutOfPlace[m - j - 1]] = element1;
            
            // What does p look like? 
            //for (int i = 0; i < n; i++) cout << p[i];
            //cout << endl;
        }
        
        // Is p sorted? 
        for (int i = 0; i < n; i++) {
            if (p[i] != (i + 1)) flag = false;
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
