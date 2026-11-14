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
    // The synthesizer has n keys, giving a_1,...,a_n units of audience love.
    // A triad starting at x brings a_x + a_{x+2} - a_{x+4} units of audience love.
    // Count the number of ways to choose two triads that do not share any keys and bring 
    // the same amount of audience love.
    
    // Input:
    // First line: t (1 ≤ t ≤ 10^4).
    // First line of each test case: n (6 ≤ n ≤ 2*10^5).
    // Second line of each test case: a_1 a_2 ... a_n (-10^4 ≤ a_i ≤ 10^4).
    // The sum of n over all test cases ≤ 2 * 10^5.
    
    // Output:
    // Each Test Case: one integer, the answer.
    
    // Test Case 1: a = [5,1,4,2,2,-4].
    // There is a unique way to choose two triads that do not share any keys and bring
    // the same amount of audience love.
    // x = 1, y = 2. 5 + 4 - 2 = 7 = 1 + 2 -(-4). 
    
    // Test Case 2: a = [0,0,0,0,0,0,0].
    // There are two ways to choose two triads that do not share any keys and bring 
    // the same amount of audience love.
    // x = 1, y = 2. x = 3, y = 2.
    // Each triad brings 0 units of audience love. 
    
    // Test Case 3: a = [-4,3,0,-4,-4,1,-4,1,-3,-2,-2,-1].
    // x = 1: 0 units of audience love. 
    // x = 2: 0 units of audience love.
    // x = 3: 0 units of audience love.
    // x = 4: -4 units of audience love.
    // x = 5: -5 units of audience love.
    // x = 6: 2 units of audience love. 
    // x = 7: -5 units of audience love. 
    // x = 8: 0 units of audience love.
    // Ways to choose two triads that do not share any keys and bring the same amount
    // of audience love: 
    // 1. x = 1, y = 2.
    // 2. x = 1, y = 8.
    // 3. x = 3, y = 1.
    // 4. x = 3, y = 8.
    // 5. x = 5, y = 7.
    // There are five ways to choose two triads that do not share any keys and bring the 
    // same amount of audience love. 
    
    /* Official Solution:
    Let f(x) = a_x + a_{x+2} - a_{x+4} be the value of the triad starting at x.
    Two triads x < y (y > x) intersect only if y - x = 2 or y - x = 4. 
    The answer (number of ways to choose two triads that do not share any keys and 
    bring the same amount of audience love) is the number of pairs x > y such that 
    f(x) = f(y), minus the pairs where y - x = 2 or y - x = 4.
    
    Sidenote: What does declaration mean? To declare a variable is to introduce its name and 
    data type to the program.
    
    Sidenote: What does initialization mean? To initialize a variable is to assign its very
    first value. 
    
    Sidenote: What is a map?
    A map stores elements in key-value pairs. 
    You access elements in a map by key, not index. 
    Elements are automatically sorted in ascending order by their keys.
    map<string, int> people; -> map called people that stores strings as keys and integers
    as values. 
    map<string, int> people = {{"Bob", 15}, {"Carol, 17"}, {"John", 29}}; -> creates map
    that will store the name and age of different people with some elements added at 
    the time of declaration. 
    
    We process y from left to right and use a map to store how many times each value of
    f has occurred. We add the number of previous occurrences of f(y) to the answer. 
    Then we separately subtract 1 if f(y-2) = f(y) and another 1 if f(y-4) = f(y): These 
    pairs have just been counted, but their triads intersect. The answer can be as large
    as ~2*10^10, so a 64-bit integer type (long long) is required.
    
    The time complexity is O(n*log(n)) due to the use of a map.
    */
    
    int t, n, curr, twoBefore, fourBefore;
    ll ans;
    vector <int> a;
    map <int, int> f;
    cin >> t;
    
    while (t--) {
        cin >> n;
        a.clear();
        f.clear();
        ans = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.pb(curr);
        }
        
        // Process y from left to right. 
        for (int i = 0; i < n - 4; i++) {
            curr = a[i] + a[i+2] - a[i+4]; // Curr is the audience love value of the triad that starts 
            // at i. 
            ans += f[curr];
            f[curr]++;
            
            // Subtract 1 if f(y) = f(y-2).
            if (i > 1) {
                twoBefore = a[i-2] + a[i] - a[i+2];
                if (curr == twoBefore) ans--;
            }
            
            // Subtract 1 if f(y) = f(y-4).
            if (i > 3) {
                fourBefore = a[i-4] + a[i-2] - a[i];
                if (curr == fourBefore) ans--;
            }
        }
        
        cout << ans << endl;
    }
}
