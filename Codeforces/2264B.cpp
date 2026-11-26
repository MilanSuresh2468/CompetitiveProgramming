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
    ios::sync_with_stdio(false); // This code speeds up the input for reasons I must understand
    // but currently do not. 
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        
        vector<ll> a;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.pb(x);
        }
        
        
        // The score is m*b_m -∑i=1->m-1(b_i).
        // We keep track of the m-1 smallest elements that have occurred and 
        // see what the score would be with those elements and the current element. 
        priority_queue<ll> pq;
        ll sum = 0, ans = LLONG_MIN; // LLONG_MIN is the minimum value of a long long in C++.
        
        for (int i = 0; i < n; i++) {
            if ((int)pq.size() == m - 1) {
                //cout << a[i];
                ans = max(ans, m * a[i] - sum);
            }
            
            pq.push(a[i]);
            sum += a[i];
            if ((int)pq.size() == m) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        cout << ans << '\n';
        
    }
}
