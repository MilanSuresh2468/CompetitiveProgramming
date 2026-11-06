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

ll intPow(int x, int y) {
    ll result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // Vadim thought of a number x. He obtained y by appending at least one zero to the 
    // right of x. n = x + y. Find all suitable x that Vadim could have thought of for 
    // the given n. 
    // First line: 1 ≤ t ≤ 10^4.
    // Each Test Case: 11 ≤ n ≤ 10^18.
    // For each number n, output the number of suitable x, followed by all suitable x 
    // in ascending order. 
    
    // Observations:
    // 1. Any suitable x must have the same last digit as n. 
    // 2. If a number contains an even amount (x) of a single digit D, then a suitable x 
    // exists: x/2 digits of D.
    // 3. There can be suitable x for a number that is all one digit. 
    
    // Test Case 1: n = 1111.
    // 2 suitable x: 11, 101.
    // x = 11: pick y = 1100. x + y = 11 + 1100 = 1111. 
    // x = 101: pick y = 1010. x + y = 101 + 1010 = 1111. 
    
    // Test Case 2: n = 12.
    // x = 1: pick y = 10. x + y = 11. pick y = 100. x + y = 101. Any greater choice of 
    // y leads to x + y > 101, so x = 1 does not work.
    // x = 2: pick y = 20. x + y = 20. Any greater choice of y leads to x + y > 20, so 
    // x = 2 does not work.
    // Any larger choice of x will run into the same issue as x = 2. 
    // Thus, there are no suitable choices for x.
    
    // Test Case 3: n = 55. 
    // x = 5. y = 50. x + y = 55. x = 5 works.
    // x = 15. y > 150. x + y > 165. x = 15 does not work.
    // Any larger choice of x runs into the same issue as x = 15. 
    // 1 suitable x: x = 5. 
    
    // Test Case 4: n = 999999999999999999 (18 9's). 
    // Three suitable x: 999999999 (9 9's), 999000999000999 (15 digits), 
    // 90909090909090909 (17 digits).
    // 1. x = 999999999. Pick y = 999999999000000000 (18 digits). x + y = 
    // 999999999999999999. 
    // 2. x = 999000999000999. Pick y = 999000999000999000 (18 digits). x + y = 
    // 999999999999999999.
    // 3. x = 90909090909090909. Pick y = 909090909090909090 (18 digits). x + y = 
    // 999999999999999999.
    
    // Test Case 5: n = 1000000000000000000 (10^18).
    // Any suitable x must end in 0. 
    // Apparently, there are no suitable x, but I am unsure how to prove that.
    
    // Try n = 121. 
    // x = 11 works. pick y = 110. x + y = 11 + 110 = 121. 
    // Takeaway: There can be suitable x for a number that is not all 1 digit.
    
    // Official Hint: If Vadim appends k zeros to the number x, what will be the
    // ratio between n and x? 
    // n/x = (x+y)/x = (x + 10^k*x)/(x) = ((x)(1+10^k))/x = 1 + 10^k. 
    // If Vadim appends k zeros to the number x, the ratio between n and x will be 
    // 1 + 10^k.
    
    // Idea: n/x = 10^k + 1 => x = n/(10^k + 1). 
    // Try different values of k and see what gives an integer x. 
    // Possible values of k: 0 to 17.
    // This does oes not work. Observe that k must be at least 1 since y must be at 
    // least 10 times x.
    
    ll t, n;
    vector <ll> x;
    cin >> t;
    
    while (t--) {
        cin >> n;
        x.clear();
        
        for (int k = 1; k < 18; k++) {
            if (n%(intPow(10, k) + 1) == 0) {
                x.pb(n/(intPow(10, k) + 1));
            }
        }
        
        cout << x.size() << endl;
        sort(x);
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        if (x.size() > 0) cout << endl;
    }
    
    return 0;
}
