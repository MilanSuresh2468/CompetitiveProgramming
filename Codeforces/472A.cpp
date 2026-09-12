#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Cases
    // n mod 4 = 0: can divide into two numbers that are divisible by 2 and thus composite.
    // n mod 4 = 2: 
    if (n%4 == 0) {
        cout << n/2 << " " << n/2;
    } else if (n%4 == 2) {
        cout << n/2 - 1 << " " << n/2 + 1;
    } else {
        cout << (n - 9) << " " << 9;
    }

    return 0;
}
