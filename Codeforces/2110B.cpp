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
    // A bracket sequence is balanced if it can be constructed by the following
    // formal grammar (set of rules for what strings are part of a language):
    // -> 1. The empty sequence is balanced.
    // -> 2. If A is balanced, (A) is balanced.
    // -> 3. If A and B are balanced, AB is balanced. 
    // Input:
    // First line: t (1 ≤ t ≤ 10^4).
    // Each test Case: s (2 ≤ |s| ≤ 2 * 10^5).
    // s is a balanced bracket sequence. 
    // The sum of |s| over all test cases does not exceed 2*10^5.
    // Output:
    // Output "YES" if it is possible to remove a '(' and a ')' such that s is no 
    // longer balanced. Otherwise, output "NO".
    
    // Test Case 1: s = "(())".
    // We first remove either s_1 or s_2. We then remove either s_3 or s_4.
    // Either way, we end up with s = "()", which is balanced.
    // We output "NO".
    
    // Test Case 2: s = "(())()()".
    // We remove s_5 and s_8. We end up with s = "(()))(", which is not a 
    // balanced bracket sequence. 
    // We output "YES".
    
    // Test Case 3: s = "()".
    // We have to remove s_1 and s_2. We are left with s = "", which is a balanced
    // bracket sequence.
    // We output "NO".
    
    // Test Case 4: s = "(())(())".
    // We can remove s_2 and s_7. We end up with s = "())(()", which is not a
    // balanced bracket sequence.
    // We output "YES".
    
    // If the sequence is composed of open parentheses followed by close parentheses,
    // it is impossible to un-balance the bracket sequence. Thus, we should output
    // "NO".
    
    // If the sequence ever contains "()()", we can make transform that substring
    // into ")(", which is not balanced. 
    
    // Potential Idea: "YES" if there are two islands of parentheses and "NO"
    // otherwise?
    
    // Observations:
    // 1. Output "NO" if the squence is open parentheses followed by close parentheses.
    
    // Official Solution:
    // Algorithm for checking the correctness of a bracket sequence: Check that 
    // the balance bal at each prefix is non-negative and that the balance bal of 
    // the entire sequence is equal to 0. Open brackets increase bal by 1, and close
    // brackets decrease bal by 1. 
    
    // To break a correct bracket sequence, we need to violate at least one of 
    // these conditions. Since the bal of the entire sequence will not change 
    // if we delete an open parenthesis and a close parenthesis, we should 
    // violate the first condition. 
    
    // It is advantageous to remove the very last close bracket since we want 
    // to add 1 to bal as late as possible.
    // It is advantageous to remove the remove the first very open bracket since 
    // we want to decrease bal by 1 as early as possible.
    
    // Answer: Is the original bracket sequence closed without the first and 
    // last brackets?
    
    int t, bal;
    string s;
    bool flag;
    cin >> t;
    
    while (t--) {
        cin >> s;
        bal = 0;
        flag = false;
        
        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == '(') bal++;
            else bal--;
            
            if (bal < 0) flag = true;
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
        
    }

    
}
