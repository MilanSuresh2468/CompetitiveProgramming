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
    // Array a of n positive integers.
    // Positive integer k.
    // While a has ≥ k elements: 
    // -> Do operation 1 or operation 2. 
    // -> Operation 1: remove a_k and add its value to your score.
    // -> Operation 2: remove a_{m - k + 1} and add its value to your score, where
    // m is the length of a before the operation. 
    // Determine the maximum obtainable score.
    // 1 ≤ t ≤ 10^4. 
    // 1 ≤ k ≤ n ≤ 10^5. 
    // 1 ≤ a_i ≤ 10^9. 
    // The sum of n over all test cases ≤ 10^5. 
    
    // Test Case 1: n = 4, k = 2. 
    // Array a = [1, 2, 3, 4]. 
    // Remove a_3 = 3. We now have score = 3, and array a = [1, 2, 4]. 
    // Remove a_2 = 2. We now have score = 5, and array a = [1, 4]. 
    // Remove a_2 = 4. We now have score = 9, and array a = [1].
    // Since a.length < k = 2, we stop doing operations.
    // Observation: a greedy algorithm (pick the operation
    // that adds more to the score) might work for this problem.
    
    // Test Case 2: n = 4, k = 2.
    // Array a = [3, 4, 1, 2].
    // Remove a_3 = 3. We now have score = 3, and array a = [4, 1, 2].
    // Since a.length < k = 4, we stop doing operations.
    // Observation: a greedy algorithm (pick the operation that adds more to the score)
    // works on test cases 1 and 2. 
    
    // Test Case 3: n = 1, k = 1. 
    // Array a = [1]. 
    // Remove a_1 = 1. We now have score = 1, and array a = []. 
    // Since a.length < k = 1, we stop doing operations. 
    // Observation: a greedy algorithm (pick the operation that adds more to the score)
    // works on test cases 1, 2, and 3. 
    
    // Test Case 4: n = 6, k = 3. 
    // Array a = [1, 4, 8, 2, 6, 3].
    // Remove a_3 = 8. We now have score = 8, and array a = [1, 4, 2, 6, 3].
    // Remove a_3 = 2. We now have score = 10, and array a = [1, 4, 6, 3]. 
    // Remove a_3 = 6. We now have score = 16, and array a = [1, 4, 3].
    // Remove a_3 = 3. We now have score = 19, and array a = [1, 4].
    // Since a.length < k, we stop doing operations. 
    // Observation: a greedy algorithm (pick the operation that adds more to the score)
    // works on test cases 1 thru 4.
    
    // I can try the above greedy algorithm, but this may be a large mistake since I have 
    // not proved that it works.
    
    // A greedy algorithm, which picks the operation that adds more to the score, 
    // appears to work but is too slow. 
    // erase takes O(n), and the loop runs n - k times, which can be as high as n - 1. 
    // Thus, the algorithm takes O(n^2) operations. This is a travesty! n ≤ 10^5. 
    
    // Test Case 4: n = 6, k = 3. 
    // a = [1, 4, 8, 2, 6, 3].
    //      0  1  2  3  4  5
    // l = 2, r = 3. Sum = 0. haveMet = false.
    // Operation 1: Remove a_2. Case 2.
    // a = [1, 4, 2, 6, 3].
    //     0   1  3  4  5
    // l = 3, r = 3. Sum = 8. haveMet = true.
    // Operation 2: Remove a_3. 
    // a = [1, 4, 6, 3].
    //     0   1  4  5 
    // l = 4, r = 1. Sum = 10. haveMet = true.
    // Operation 3: Remove a_4.
    // a = [1, 4, 3].
    //     0   1  5 
    // l = 5, r = 0. Sum = 16. haveMet = true.
    // Operation 4: Remove a_5. 
    // a = [1, 4].
    
    // Question: How would picking a_1 for operation 3 affect l and r? 
    // a = [1, 6, 3]. 
    //     0   4  5 
    // l = 5, r = 0. Sum = 4. 
    // Answer: picking a_1 for operation 3 would increase l by 1 and decrease r by 1. 
    
    // Question: What happens when l and r meet? 
    // Answer: After the operation, r is 1 less than the initial value of l, and l 
    // is 1 more than the initial value of r. Future operations increase l by 1 and
    // decrease r by 1. 
    
    // New plan: instead of using erase, keep track of two pointers. Have a flag that
    // changes how we update the pointers after they meet. 
    
    ll t, n, k, m, l, r, sum, curr;
    bool haveMet;
    vector <ll> a;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        sum = 0;
        a.clear();
        m = n;
        l = k - 1; 
        r = m - k;
        if (r <= l) haveMet = true;
        else haveMet = false;
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.pb(curr);
        }
        
        while (m >= k) {
            
            // Cases:
            // Case 1: l and r have not met, a[r] > a[l].
            // -> add a[r] to score. 
            // -> r--. 
            // Case 2: l and r have not met, a[l] ≥ a[r].
            // -> add a[l] to score.
            // -> l++.
            // Case 3: l and r are meeting.
            // -> haveMet = true.
            // -> add a[l] to score. 
            // -> l = m - k, r = k - 2. 
            // Case 4: l and r have met, a[r] > a[l].
            // -> add a[r] to score. 
            // -> l++, r--.
            // Case 5: l and r have met, a[l] ≥ a[r].
            // -> add a[l] to score.
            // -> l++, r--.
            
            //cout << a[l] << " " << a[r] << endl;
            
            //cout << "haveMet: " << haveMet << endl;
            //cout << "a[l]: " << a[l] << " a[r]:" << a[r] << endl;
            if (l == r) haveMet = true;
            
            if (!haveMet && a[r] > a[l]) {
                //out << "Case 1\n";
                
                sum += a[r];
                r--;
            } else if (!haveMet && a[l] >= a[r]) {
                //cout << "Case 2\n";
                
                sum += a[l];
                l++;
            } else if (l == r) {
                //cout << "Case 3\n";
                sum += a[l];
                l = n - k + 1;
                r = k - 2;
            } else if (haveMet && a[r] > a[l]) {
                //cout << "Case 4\n";
                //cout << a[r] << endl;
                sum += a[r];
                l++;
                r--;
            } else {
                //cout << "Case 5\n";
                
                sum += a[l];
                l++;
                r--;
            }
            
            m--;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
