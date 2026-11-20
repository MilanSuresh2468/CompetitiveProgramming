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
    // s is a binary string of length n. 
    // Operation: Choose an index i. Replace s_i with either the bitwise AND or the bitwise OR of
    // s_1,...,s_i.
    // ->If s_1,...,s_i contains a single 0, and we choose bitwise AND, s_i := 0. Otherwise, s_i := 1.
    // ->If s_1,...,s_i contains a single 1, and we choose bitwise OR, s_i := 1. Otherwise, s_i := 0.
    // Note that the bitwise AND or bitwise OR of a single element is equal to the element itself.
    
    // Find the minimum number of operations required to sort s.
    
    // Input:
    // First Line: t (1 ≤ t ≤ 10^4) - the number of test cases. 
    // First line of each test case: n (2 ≤ n ≤ 2 * 10^5) - the length of s.
    // Second line of each test case: s. 
    // The sum of n over all test cases does not exceed 2 * 10^5. 
    // Output:
    // For each test case, print the minimum number of operations required to sort s.
    
    // Test Case 1: 0011.
    // l = 3. r = 2. 
    // There are no elements from l = 3 to r = 2, so we can sort s in 0 operations.
    
    // Test Case 2: 1000.
    // l = 1, r = 4.
    // We cannot change the elements from l to r to all 0's since the bitwise OR or the bitwise AND 
    // of s_1 = 1 would yield s_1 = 1.
    // Hence, we should change the elements from l to r to all 1's.
    // There are 3 0's from l to r, so we can sort s in 3 operations. 
    
    // Test Case 3: 01000. 
    // l = 2, r = 5.
    // There are 3 0's and 1 1 from l to r, so it is cheaper to make the elements from l to r
    // all 0's. This costs 1 operation.
    // We can sort s in 1 operation.
    
    // Test Case 4: 01001101.
    // l = 2, r = 7.
    // There are 3 0's and 3 1's from l to r. We can make the elements from l to r all 1's or all 0's 
    // in 3 operations.
    // Apparently, there is a cheaper way to sort s!
    // s_2 = the bitwise AND of s_1,s_2. 
    // s = 00001101. 
    // s_7 = the bitwise OR of s_1,...,s_7.
    // s = 00001111.
    // Interesting, I need to think some more.
    
    // Test Case 5: 0101010.
    // The first 1 is at position 2. The last 0 is at position 7.
    // s_2 := bitwise OR of s_1,s_2. 
    // s_4 := bitwise OR of s_1,...,s_4.
    // s_6 := bitwise OR of s_1,...,s_7.
    // We sorted s in 3 operations, which is optimal!
    
    // Test Case 6: 0111101.
    // The first 1 is at position 2. The last 0 is at position 6. 
    // There are 4 1's and 1 0 from position 2 to 6.
    // It is cheaper to make s_l,...,s_r all 1's than all 0's.
    // s_6 := bitwise OR of s_1,...,s_6.
    // We sorted s in 1 operation, which is optimal!
    
    // Observations:
    // ->We do not need to change what comes after the last 0.
    // ->We do not need to change what comes before the first 1.
    // ->Hint: If a prefix contains both 0 and 1, its bitwise AND is 0, and its bitwise OR is 1.
    // ->Hint: A sorted binary string s is determined by one split point, where s goes from all 0's 
    // to all 1's.
    
    // Failed Solution:
    // ->Say that the first 1 is at position l and last 0 is at position r. 
    // ->We should see if it is cheaper to change the elements at l through r to all 0's or all 1's.
    // ->If l = 1, then we must make the elements at positions l through r all 1's.
    
    // Official Solution:
    // If a prefix contains both 0 and 1, its AND is 0 and its OR is 1, so the last character 
    // can be changed to either value. 
    // If s_1 = 1, the first character can never change, so the final string must be all ones. Every 
    // zero can be changed using OR, giving the number of zeros as the answer. 
    // Now suppose s_1 = 0. Fix the point after which the ones start. For a split after i, we 
    // need to change every one in [1,i] and every zero in [i+1,n]. We can first change the required
    // zeros on the right using OR, then change the required ones on the left using AND. A split inside 
    // the initial block of zeros is never better than moving it to the end of the block.
    // So, scan every split while maintaining the number of ones on the left and zeros on the right, and 
    // take the minimum.
    
    int t, n, zeroCount, minimum;
    vector <int> ones, zeros;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> n >> s;
        ones.assign(n, 0);
        zeros.assign(n+1, 0);
        
        if (s[0] == '1') {
            zeroCount = 0;
            
            for (int i = 1; i < n; i++) {
                if (s[i] == '0') zeroCount++;
            }
            
            cout << zeroCount << endl;
        } else {
            if (s[0] == '1') ones[0]++;
            if (s[n-1] == '0') zeros[n-1]++;
            
            // Count zeros. 
            for (int i = n - 2; i >= 0; i--) {
                zeros[i] = zeros[i+1];
                if (s[i] == '0') zeros[i]++;
            }
            
            // Count ones.
            for (int i = 1; i < n; i++) {
                ones[i] = ones[i-1];
                if (s[i] == '1') ones[i]++;
            }
            
            // Find the minimum number of operations required to sort s in non-decreasing order.
            minimum = 10E9;
            for (int i = 0; i < n; i++) {
                if ((ones[i] + zeros[i+1]) < minimum) minimum = ones[i] + zeros[i+1];
            }
            
            cout << minimum << endl;
        }
    }
    
    cin.tie(0);
}
