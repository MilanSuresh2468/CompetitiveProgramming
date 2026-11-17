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
    // mex_k(x) is the smallest non-negative integer that appears k or fewer times in a multiset x. 
    // Input:
    // ->First Line: t (1 ≤ t ≤ 10^4).
    // ->First line of each test case: n k (2 ≤ n ≤ 2*10^5, n is even, 1 ≤ k ≤ n). 
    // ->Second line of each test case: a_1 a_2 ... a_n (0 ≤ a_i ≤ n).
    // n is the number of cards, and k is the parameter of the game. 
    // a_i is the number written on the i-th card.
    // The sum of n over all test cases does not exceed 2 * 10^5.
    // Output:
    // For each test case, output "Yes" if Alice wins if both players play optimally and "NO" otherwise.
    
    // Alice and Bob play a game, with Alice starting. On each turn, the current player takes one 
    // of the remaining cards until all of the n cards have been taken. 
    // Let x be the multiset of integers written on Alice's cards. Let y be the multiset of integers
    // written on Bob's cards.
    // Alice wins if mex_k(x) ≠ mex_k(y), and Bob wins otherwise.
    
    // Test Case 1: a = [2,0,0,1], k = 1.
    // Alice can take the card with 1 on it on her first turn and the card with 0 on it on her second turn.
    // Then, mex_1(x) = mex_1({1,0}) = 2, and mex_1(y) = mex_1({2,0}) = 1. mex_1(x) ≠ mex_1(y), so Alice 
    // wins. Alice can take this sequence of moves no matter what, so Alice wins under optimal play. 
    // The answer is "YES". 
    
    // Question: Is "Alice wins if both players play optimally" <=> "Alice has a sequence of strictly 
    // winning "moves"? No. 
    // =>: No, Alice's winning moves may depend no Bob's moves. 
    // <=: Yes, if Alice always plays the sequence of strictly winning moves, then she wins even if 
    // Bob plays optimally.
    
    // Test Case 2: a = [0,1,0,1], k = 1. 
    // W.L.O.G., say that Alice picks 1. Then Bob can pick 1. This means Alice and Bob must then pick 0.
    // x = {1,0}, y = {1,0}. mex_k(x) = 2 = mex_k(y), so Bob wins under any circumstance. Thus, 
    // Bob wins. The answer is "NO".
    
    // Test Case 3: a = [1, 2, 0, 1, 0, 0], k = 2. 
    // Alice can pick 0. 
    // Bob can pick any number, including 0. 
    // Alice can pick 0. 
    // Bob can pick any number. 
    // mex_k(x) != 0, but mex_k(y) = 0 since Bob has ≤ 1 0's. Thus, Alice wins no matter what. 
    // The answer is "YES".
    
    // Test Case 4: a = [0,0,1,1,2,2], k = 2. 
    // W.L.O.G, say the following sequence of moves happens. Alice picks 0. Bob picks 0. Alice picks 1.
    // Bob picks 1. Alice picks 2. Bob picks 2. mex_k(x) = mex_2({0,1,2}) = 0 = mex_2({0,1,2}) = mex_k(y).
    // Bob wins. The answer is "NO".
    
    // Observation:
    // ->Output "NO" if there is at least one case where Alice loses. 
    
    // Test Case 5: a = [0,1,1,0,0,2,0,1], k = 2. 
    // Alice picks 1.
    // ->Bob picks 1. Alice picks 1. Bob picks some number. Alice picks 0. Bob picks some number. Alice picks
    // 0. x contains 2 0's and 2 1's, so mex_k(x) ≥ 2. y contains at most a single 1, so mex_y ≤ 1. 
    // -> Bob picks 0. I am not sure what happens in this case. 
    
    // Official Solution:
    // Let cnt[x] be the number of cards containing x. 
    // We will consider the integers x = 0,1,...,n in increasing order and find the first x 
    // such that cnt[x] < 2k. 
    // We claim that Alice wins if and only if cnt[x] = 2k - 1.
    // Case 1: cnt[x] = 2k - 1.
    // We will show that is impossible for Alice and Bob to have the same mex_k, regardless of how 
    // they play. 
    // Suppose both players have the same mex_k = y. We consider 3 cases. 
    // ->If y < x, both players must have fewer than k cards containing y. This is impossible because 
    // cnt[y] ≥ 2k.
    
    cin.tie(0);
    int t, n, k, curr;
    bool flag;
    vector <int> cnt;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        flag = false;
        cnt.assign(n+1, 0);
        for (int i = 0; i < n; i++) {
            cin >> curr;
            cnt[curr]++;
        }
        
        for (int i = 0; i <= n; i++) {
            if (cnt[i] < 2*k) {
                if (cnt[i] == (2*k - 1)) {
                    flag = true;
                    break;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}
