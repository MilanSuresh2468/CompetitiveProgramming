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
    // You are given integers n, k, and m.
    // n: number of children in the school, 1 ≤ n ≤ 5000.
    // t_i = 1 if the i-th child is good at programming, t_i = 2 if the i_th child is 
    // good at maths, and t_i = 3 if the i_th child is good at PE. 
    // First line: n. Second line: t_1,t_2,...,t_n.
    // Each team has one mathematician, one programmer, and one sportsman. 
    // First line: w, the max amount of teams that can be formed.
    // Next w lines: children in each team.
    
    int n, curr, numberOfTeams;
    vector <int> programming, maths, PE;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> curr;
        if (curr == 1) programming.pb(i);
        else if (curr == 2) maths.pb(i);
        else PE.pb(i);
    }
    
    numberOfTeams = min(min(programming.size(), maths.size()), PE.size());
    cout << numberOfTeams << endl;
    for (int i = 0; i < numberOfTeams; i++) {
        cout << programming[i] << " " << maths[i] << " " << PE[i] << endl;
    }
    
    return 0;
}
