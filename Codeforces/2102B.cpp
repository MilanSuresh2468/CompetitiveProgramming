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
    // You have an array a of length n.
    // You can negative as many elements of a as you want.
    // Determine if it is possible to make a_1 the median of the array.
    // The median of array b is the ceil(m/2)-th element. 
    // All elements of a differ in terms of absolute value.
    // Observations:
    // ->The order of elements does not affect the median, so we can look at the sorted array 
    // and keep track of the first element.
    // ->If the length of a is 1 or 2, we should always return "YES".
    
    // Test Case 1: a = [2,1,3] ([1,2,3]). First element: 2. 
    // The first element is the median, even if we do not perform any negations.
    
    // Test Case 2: a = [1,2,3,4,5]. First element: 1.
    // a = [1,2,3,-4,-5] ([-5,-4,1,2,3]). The median is the first element as desired.
    
    // Test Case 3: a = [4,2,0,-5] (-5,0,2,4). First element: 4. 
    // a = [0,2,4,5]. The median is the first element as desired.
    
    // Test Case 4: a = [-5,0,4,3] (-5,0,3,4). First element: -5. 
    // -5 is always the smallest element. 5 is always the biggest element. We cannot make 
    // the median the first element.
    
    // Test Case 5: a = [-10,8,3,2] (-10,2,3,8). First element = -10.
    // -10 is always the smallest element, and 10 is always the biggest element. We cannot make
    // the median the first element. 
    
    // Test Case 6: a = [1]. First element = 1. 
    // The first element is the median. 
    
    // Test Case 7: a = [9,1000,-999,-13,456,-223,23,24,10,0] (-999,-223,-130,0,9,10,23,24,1000).
    // First element = 9. 
    // The first element is the median.
    
    // Represent a as follows.
    // Make all entries of a positive and sort a.
    
    // Say we have [1,2,3,4,5].
    // 1,2,3 can become the median. 
    
    // Theory elements with indices 1 to ceiling(length/2) can become the median.
    
    cin.tie(0);
    int t, n, curr, firstElement;
    bool flag;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        cin >> n;
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> curr;
            if (i == 0) firstElement = abs(curr);
            a.pb(abs(curr));
        }
        sort(a);
        flag = false;
        
        if (n <= 2) {
            cout << "YES\n";
        } else {
            for (int i = 0; i <= floor(n/2); i++) {
                if (a[i] == firstElement) flag = true;
            }
            
            if (flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
