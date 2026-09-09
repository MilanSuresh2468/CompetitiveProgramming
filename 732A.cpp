#include <bits/stdc++.h>
using namespace std;

int main() {
    // Shovel sold for k buries
    
    // Polycarp has infinite 10-burle coins and 1 r burle coin (1 <= r <= 9)
    // Min number of shovels such that Polycarp can pay for the purchase
    // without change
    
    // Find min number of shovels Polycarp can buy without any change.
    // Can pay for 10 shovels without any change (10 shovels cost 10k. 
    // Can use k 10-burle coins to pay for the 10 shovels without any change).
    // Must buy at least 1 shovel
    
    // Idea: increment num of shovels up and see if he can pay for that num
    // of shovels without any change.
    
    int k; // Price of 1 shovel; 1 <= k <= 1000
    int r; // Denomination of other type of coin (1 <= r <= 9)
    cin >> k >> r;
    
    for (int i = 1; i <= 10; i++) {
        if ((k*i)%10 == 0 || (k*i - r)%10 == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}
