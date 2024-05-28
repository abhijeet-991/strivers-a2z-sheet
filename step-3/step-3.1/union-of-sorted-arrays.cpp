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
void invokePrime(bool(&prime)[1000001]) {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 1000001; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 1000001; i += p) {
                prime[i] = false;
            }
        }
    }
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
class Solution {
public:
    vector<int> findUnion(int a[], int b[], int n, int m) {
        vector<int>ans;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
            }
            else {
                if (ans.empty() || ans.back() != b[j]) {
                    ans.push_back(b[j]);
                }
                if (a[i] == b[j]) i++;
                j++;
            }
        }
        while (i < n) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        while (j < m) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};
void solve() {
    // int n; cin >> n;
    // vector<int>a1, a2;
    // for (int i = 0;i < n;i++) {
    //     int x; cin >> x;
    //     a1.push_back(x);
    // }
    // int m; cin>>m;
    // for (int i = 0;i < m;i++) {
    //     int x;cin >> x;
    //     a2.push_back(x);
    // }
    int a1[] = { 1,2,3 };
    int a2[] = { 2,3,6 };
    // int a1[] = { 1,2,3,4,5 };
    // int a2[] = { 1,2,3 };
    Solution solution;
    vector<int> ans = solution.findUnion(a1, a2, 3, 3);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    solve();
    return 0;
}