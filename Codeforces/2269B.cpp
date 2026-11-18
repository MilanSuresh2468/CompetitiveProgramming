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

int f(int x) {
    int curr = x; // We use curr to go through each digit of x. 
    int sum = 0; // the sum of the squares of x's digits.
    
    while (curr > 0) {
        sum += (curr%10)*(curr%10);
        curr /= 10;
    }
    
    return sum;
}


int main() {
    cin.tie(0);
    // Law of lighthouses: If a lighthouse shows x tonight, it shows the sum of the squares of x's 
    // digits tomorrow. 
    // On night 0, lighthouse i shows the number a_i. 
    // Lighthouses i and j are in tune if there exists a night after which, forever, both
    // show the same number on every night.
    // How many pairs (i,j) with i < j are in tune? 
    // Input:
    // First line: t (1 ≤ t ≤ 1000) - the number of test cases.
    // Each test case consists of two lines:
    // Line 1: n (1 ≤ n ≤ 1000) - the number of lighthouses.
    // Line 2: a_1 a_2 ... a_n (1 ≤ a_i ≤ 10^9) - the number shown on each lighthouse on night 0.
    // The sum of n over all test cases does not exceed 1000.
    // Output:
    // For each test case, print the number of pairs (i,j) where i < j that are in tune.
    
    // Test Case 1: 
    // 7  4  16  4  2 
    // 49 16  37  16 4
    // 97 37  58  37  16 
    // 130 
    // 10 
    // 1
    // 16 -> 37 -> 58 -> 89 -> 165 -> 62 -> 40 -> 16 -> 37 
    // 2  -> 4  -> 16 -> 37 -> 58  -> 89 -> 165 -> 62 -> 40 -> 16 
    // Lighthouses 3 and 5 have cycles that do not seem to ever overlap.
    // Lighthouse 1 stays at 1 forever after some point.
    // Lighthouses 2 and 4 both start at 4 and show the same number on every night.
    // Lighthouse 3 starts at 16, and lighthouse 5 starts at 2. Each of them is at a 
    // different point of the cycle and never matches anybody. 
    // The only pair in tune is (2,4).
    
    // Test Case 2: 
    // 1 7 10 100
    // All elements become 1 forever at some point.
    // Valid pairs: (1,4), (1,3), (1,2), (2,3), (2,4), (3,4).
    
    // Test Case 3: 
    // 0. 4 16 37
    // 4^2 = 16.
    // 1^2 + 6^2 = 1 + 36 = 37.
    // 3^2 + 7^2 = 9 + 49 = 58. 
    // 1. 16 37 58. 
    // 1^2 + 6^2 = 1 + 36 = 37.
    // 3^2 + 7^2 = 9 + 49 = 58.
    // 5^2 + 8^2 = 25 + 64 = 89.
    // 2. 37 58 89. 
    // 3^2 + 7^2 = 9 + 49 = 58.
    // 5^2 + 8^2 = 25 + 64 = 89.
    // 8^2 + 9^2 = 64 + 81 = 145. 
    // 3. 58 89 145.
    // 5^2 + 8^2 = 25 + 64 = 89. 
    // 8^2 + 9^2 = 64 + 81 = 145. 
    // 1^2 + 4^2 + 5^2 = 1 + 16 + 25 = 42. 
    // 4. 89 145 42. 
    // 8^2 + 9^2 = 64 + 81 = 145.
    // 1^2 + 4^2 + 5^2 = 1 + 16 + 25 = 42. 
    // 4^2 + 2^2 = 16 + 4 = 20.
    // 5. 145 42 20.
    // 1^2 + 4^2 + 5^2 = 1 + 15 + 25 = 42.
    // 4^2 + 2^2 = 16 = 4 = 20.
    // 2^2 + 0^2 = 4 + 0 = 4. 
    // 6. 42 20 4. 
    // 4^2 + 2^2 = 16 + 4 = 20.
    // 2^2 + 0^2 = 4 + 0 = 4.
    // 4^2 = 16.
    // 7. 20 4 16 
    // 8. 4 16 37. 
    // The above pattern, where no lighthouse ever shares a number, repeats indefinitely every
    // 8 days, so there are no pairs (i, j) where i < j that are in tune. 
    
    // Test Case 4: 
    // 0: 2 20 4 
    // 1: 4 4 16 
    // 2: 16 16 37 
    // 3: 37 37 58 
    // 4: 58 58 89 
    // 5: 89 89 145 
    // 6: 145 145 42 
    // 7: 42 42 20 
    // 8: 20 20 4 
    // The After day 1, (1,2) is in tune. The pattern where lightouses 1 and 2 match but do not equal
    // lighthouse 3 repeats every 8 days, so only (1,2) is in tune.
    
    // Official Solution:
    // Let f(x) be the sum of the squares of the digits of x.
    // The only cycles of the function f(x) are 1 -> 1 and 4 -> 16 -> 37 -> 58 -> 89 -> 145
    // -> 42 -> 20 -> 4. Every positive integer eventually reaches exactly one of the two cycles.
    
    // For each initial value a_i, we simulate the process until it reaches one of the two cycles.
    // If it reaches 1, we assign it the signature 8.
    // Otherwise, suppose it takes s operations to reach the element at position k of the 8-cycle,
    // where the positions are numbered from 0 to 7.
    // Its position after t operations is (k + t - s) mod 8.
    // Therefore, two numbers entering the 8-cycle will eventually have identical values at every 
    // step i.f.f. (k_1 - s_1) is equivalent to (k_2 - s_2) (mod 8).
    // We use this value as the signature of each number. 
    // Thus, two initial values are in tune if and only if their signatures are equal.
    // Let cnt[x] be the number of elements with the signature x. The answer is ∑x=0->8 cnt[x](cnt[x]-1)/2. 
    // Since every number reaches a cycle after a constant number of operations, we can calculate all
    // signatures and count the pairs in O(n) time per test case. 
    
    int t, n, curr;
    cin >> t;
    vector <int> a, cnt;
    
    while (t--) {
        cin >> n; 
        a.clear();
        cnt.assign(9,0);
        
        for (int i = 0; i < n; i++) cin >> curr, a.pb(curr);
        
        // Calculate the signatures. 
        for (int i = 0; i < n; i++) {
            curr = a[i];
            // I assume that a number enters a cycle within 1000 operations. 
            for (int i = 0; i < 1000; i++) {
                curr = f(curr);
                if (curr == 1) {
                    cnt[8]++;
                    break;
                } else if (curr == 4) {
                    cnt[i%8]++;
                    break;
                }
            }
        }
        
        curr = 0;
        for (int i = 0; i < 9; i++) {
            curr += (cnt[i] * (cnt[i] - 1))/2;
        }
        
        cout << curr << endl;
    }
}
