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
    cin.tie(0);
    int curr;
    vector <int> nums;
    
    for (int i = 0; i < 3; i++) {
        cin >> curr;
        nums.pb(curr);
    }
    
    cout << max(max((nums[0] + nums[1]) * nums[2],
                nums[0] + nums[1] + nums[2]),
                max(nums[0] * (nums[1] + nums[2]),
                nums[0] * nums[1] * nums[2]));
}
