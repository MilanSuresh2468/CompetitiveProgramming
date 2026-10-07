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
    // n fields, n/k farms, k|n.
    // Each farm is k consecutive fields.
    // Field i is in the ceil(i/k)-th farm.
    
    // Nhoj owns some fields and will charge John extra to build a school there.
    // What is the min number of times John would have to build a school on Nhoj's land
    // to ensure each farm has at least one school? 
    
    // Count the number of farms that consist all of fields own by Nhoj. 
    
    int t, n, k, currIndex, count;
    bool allNhoj;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> s;
        currIndex = 0;
        count = 0;
        
        for (int i = 0; i < n/k; i++) {
            allNhoj = true;
            
            for (int i = 0; i < k; i++) {
                if (s[currIndex] == '0') {
                    allNhoj = false;
                }
                currIndex++;
            }
            
            if (allNhoj) count++;
        }
        
        cout << count << endl;
    }
    return 0;
}
