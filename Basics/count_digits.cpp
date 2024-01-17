#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <math.h>
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
// void solve() {
//     int n, ans=0; cin>>n;
//     while(n) {
//         n/=10;
//         ans++;
//     }
//     cout << ans << endl;
// }
template <typename T>
T solve() {
    int n; cin>>n;
    int ans = floor(log10(n))+1;
    return ans;
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    // solve();
    cout << solve<int>() << "\n";
    return 0;
}