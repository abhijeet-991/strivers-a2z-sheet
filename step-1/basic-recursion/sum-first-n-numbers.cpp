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
int functionalRecursiveSum(int n) {
    if(n == 0) return 0;
    return n + functionalRecursiveSum(n-1);
}
void parameterizedRecursiveSum(int n, int sum) {
    if(n == 0) {
        cout << sum << "\n";
        return;
    }
    parameterizedRecursiveSum(n-1, sum+n);
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    int n; cin>>n;
    // cout << functionalRecursiveSum(n) << "\n";
    parameterizedRecursiveSum(n, 0);
    return 0;
}