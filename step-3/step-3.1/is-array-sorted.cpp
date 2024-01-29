#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #define int long long
using namespace std;
#define tc \
    int t; \
    cin >> t; \
    while (t--)
int power(int x, unsigned int y) {
    if (y == 0) return 1;
    int xkn2 = power(x, y / 2);
    int xkn = xkn2 * xkn2;
    if (y & 1) xkn *= x;
    return xkn;
}
void invokePrime(bool (&prime)[1000001]) {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 1000001; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 1000001; i += p) {
                prime[i] = false;
            }
        }
    }
}
int isSorted(int n, vector<int> a) {
    for(int i = 0; i < n-1 ; i++) {
        if(a[i] > a[i+1]) return 0;
    }
    return 1;
}
void solve() {
    int n; cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    cout << isSorted(n, v) << "\n";
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    solve();
    return 0;
}