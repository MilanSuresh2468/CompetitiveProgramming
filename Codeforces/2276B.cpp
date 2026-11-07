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
    // You are given a binary string s of length n. 
    // You must perform exactly one operation consisting of two steps:
    // -> 1. Reverse a character with index from 2 to n - 1 inclusive or choose to reverse 
    // no character.
    // -> 2. Replace each maximal block of equal characters with one such character.
    // Count the number of different strings that can be obtained after performing
    // this operation. 
    // Input:
    // First Line: t (1 ≤ t ≤ 10^4).
    // Each test case: s (3 ≤ s ≤ 3 * 10^5).
    // The sum of the lengths of string s over all test cases does not exceed 3 * 10^5.
    // Output: 
    // Each Test Case: One integer, the number of different strings that can be obtained
    // after performing the operation.
    
    // Test Case 1: s = "001".
    // -> You can use the operation to replace the second character or no character.
    // -> s becomes "011". 
    // -> Both strings are "01" after compression, so only 1 different string can be
    // obtained after performing the operation.
    
    // Test Case 2: s = "000".
    // You can use the operation to replace the second character or no character.
    // s becomes "010".
    // The original string is "0" after compression. The other string is "010" after
    // compression. Thus, two different strings can be obtained after performing the 
    // operation.
    
    // Idea: Changing characters on the border does not matter. 
    // For example, if we have s = "011", flipping s_2 makes s = "001". 
    // Either way, the compressed string is "01". Thus, only one different string
    // can be obtained after performing the operation.
    
    // Idea: Is this number of obtainable strings 1 + the number of blocks of length 3
    // or more?
    // No, s = "010" has no block of length 3 or more, but we can obtain two different
    // strings.
    
    // Test Case 3: s = "010".
    // If we replace no character, the compressed string is "010".
    // If we replace s_2, the compressed string is "000".
    // Two different strings can be obtained after performing the operation. 
    
    // Test Case 4: s = "00010".
    // Options:
    // ->"00010" -> "010".
    // ->"01010" -> "01010".
    // ->"00110" -> "010".
    // ->"00000" -> "0".
    // Three different strings can be obtained after performing the operation.
    
    // Observations:
    // 1. If s_i is adjacent to '0' and '1', then flipping s_i does not change the 
    // compressed string. 
    // 2. Changing a string matters if it creates a new block.
    
    // Official Solution:
    /*
    If the first and last characters of the original string cannot be changed, then the
    first and last characters of the compressed string also remain unchanged. Since in
    the compressed string, every character differs from the previous one, we are only 
    interested in the possible different lengths of the compressed string that we can obtain:
    For each length, there is only one compressed string with fixed first and last characters.
    
    In addition, the compressed and uncompressed strings have the same number of pairs of
    different adjacent characters, and the length of the compressed string depends on it
    (it is 1 greater than the number of adjacent pairs that differ from each other). Changing
    a character affects at most two pairs of adjacent characters, so the length of the compressed
    version can change by at most 2. 
    
    It also cannot change by exactly 1 because we do not change the boundary characters.
    
    Thus, it is sufficient to check whether the length of the compressed version can be
    increased or decreased by 2. To increase the length of the compressed version by 2,
    we need to replace the middle character in a substring "111" or "000". This increases 
    the answer, the number of different strings we can obtain by 1. To decrease the length by 
    2, we need to replace the middle character in "101" or "010". This increases the 
    answer by 1.
    */
    
    // Algorithm:
    // ans = 1.
    // If "111" or "000" appears in s, increase ans by 1.
    // If "101" or "010" appears in s, increase ans by 1. 
    // Print ans.
    
    int t, ans;
    string s, curr;
    cin >> t;
    
    while (t--) {
        ans = 1;
        cin >> s;
        
        for (int i = 0; i < s.length() - 2; i++) {
            curr = s.substr(i,3);
            if (curr == "111" || curr == "000") {
                ans++;
                break;
            }
        }
        
        for (int i = 0; i < s.length() - 2; i++) {
            curr = s.substr(i, 3);
            if (curr == "101" || curr == "010") {
                ans++;
                break;
            }
        }
        
        cout << ans << endl;
    }
}
