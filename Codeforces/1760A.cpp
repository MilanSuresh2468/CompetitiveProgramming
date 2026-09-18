#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c;
    
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << a + b + c - min(min(a, b), c) - max(max(a, b), c) << endl;
    }

    return 0;
}
