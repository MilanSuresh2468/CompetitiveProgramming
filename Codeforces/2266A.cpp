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
    // Three problems, n participants
    // Prob 1 is easy. Prob 2 is medium. Prob 3 is hard.
    // A participant is weak if they did not solve every problem.
    // Array a of length 3 where a_i is the number of participants
    // that solved problem i.
    // Find the minimum possible number of weak participants.
    // n - min(min(a_1, a_2), a_3)
    
    // Resubmit so that ThemeCP Updates
    
    int t, n, a_1, a_2, a_3;
    cin >> t;
    
    while (t--) {
        cin >> n >> a_1 >> a_2 >> a_3;
        cout << n - min(min(a_1, a_2), a_3) << endl;
    }
    return 0;
}
