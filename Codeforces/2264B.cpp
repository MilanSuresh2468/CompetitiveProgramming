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
    // Given an a single integer n. Construct an array of n distinct positive integers
    // a_1,...,a_n such that for all i (1≤i≤n), a_1 + a_2 +...+a_n is divisible by a_i,
    // or determine that no such array exists.
    // In simpler terms, find n different numbers with a sum divisible by all of those 
    // numbers.
    // 1≤t≤50.
    // 1≤n≤50.
    // No solution: output -1.
    // 1≤a_i≤10^17.
    
    // n = 1: a = [1].
    // n = 2: -1.
    // n = 3: a = [1,2,3].
    // n = 4: a = [1,9,2,6].
    // n = 5: a = [12, 3, 10, 20, 15].
    
    // Ideas:
    // ->Find recursion between a_1,...,a_k and a_1,...,a_{k-1}.
    // ->Find general takeaway from n = 2 case.
    
    // Is it possible to find two distinct positive integers that both divide their sum?
    // Say we have two such numbers y > x. y|(x+y) | x|(x+y) => xy|(x+y) => (x+y) = xyq 
    // for some positive number q. Assume x > 1. Then (x+y) ≥ 2yq ≥ 2y => x > y, which 
    // is a contradiction. Clearly, we have x = 1. Therefore, the pair must be 
    // (1, y). For this pair to work, we would have to have y|(y+1), which cannot
    // be true. Hence, it is not possible to find two distinct positive integers that
    // both divide their sum.
    
    // Idea for going through solutions: I should note down what ideas of mine were useful.
    
    // Official Solution: A construction exists for all n ≠ 2.
    // First, consider the case n = 2, and suppose a solution a = [x, y] exists. Since
    // x and y both divide x + y, lcm(x, y) must also divide x + y. However x ≠ y, so
    // lcm(x, y) ≥ 2 * max(a,b) > a + b, which is a contradiction.
    
    // For the remaining cases, let a^k be our construction for n = k, and let ∑(a^k) be
    // the sum of all elements in a^k. We construct a^k recursively for all k ≤ 50:
    // ->n = 1: a^1 = [1].
    // ->n = 3: a^3 = [1,2,3].
    // ->n > 3: Construct a^{n-1}. Obtain n be appending ∑(a^{n-1}) to a^{n-1}. All 
    // elements in a^n must divide ∑(a^{n-1}), so they must also divide ∑(a^n) = 2*
    // ∑(a^{n-1}).
    
    // Since n ≤ 50 and the sum doubles for all n ≥ 3, ∑(a^n) < 2^50 ≤ 10^17 as required.
    
    vector<ll> solution = {1, 2, 3};
    ll sum = 6;
    for (int i = 0; i < 47; i++) {
        solution.pb(sum);
        sum *= 2;
    }
    
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) cout << solution[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
