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
template <typename T>
T solve() {
    int n; cin>>n;
    int ans=0;
    while(n) {
        int temp = n%10;
        ans = ans*10 + temp;
        n/=10;
    }
    return ans;
}
// void solve() {
    
// }
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    // solve();
    cout << solve<int>() << endl;
    return 0;
}