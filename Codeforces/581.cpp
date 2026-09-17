#include <bits/stdc++.h>
using namespace std;

int main() {
    // a: number of red socks; b: number of blue socks
    
    int a, b;
    cin >> a >> b;
    
    // The number of days Vasya can wear different socks = min(a,b)
    // The number of days he can wear the same socks = (a + b - 2*min(a, b))/2
    
    cout << min(a, b) << " " << (a + b - 2*min(a, b))/2;

    return 0;
}
