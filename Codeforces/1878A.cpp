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
    // A number is *most common* on a subsegment if that number occurs the most in that 
    // subsegment. 
    
    // Subsegment: consecutive segment of elements in the array a.
    
    // If k is in a, we can construct a subsegment of a single occurence of k. In this
    // subsegment, k is the most common element. 
    
    int t, n, k, curr;
    bool flag;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        flag = false;
        
        while (n--) {
            cin >> curr;
            if (curr == k) {;
                flag = true;
            }
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
