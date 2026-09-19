#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, max = 0, total = 0, curr;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (curr > max) max = curr;
        total += curr;
    }
    
    cout << max*n - total;

    return 0;
}
