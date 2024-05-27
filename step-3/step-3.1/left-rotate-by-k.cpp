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
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverseArray(nums, nums.size() - k, nums.size() - 1);
        reverseArray(nums, 0, nums.size() - k - 1);
        reverseArray(nums, 0, nums.size() - 1);
    }
private:
    void reverseArray(vector<int>& a, int start, int end) { //send with 0 based indexing
        while (start < end) {
            swap(a[start], a[end]);
            start++;
            end--;
        }
    }
};
void solve() {
    int n, k; cin >> n >> k;
    vector<int>a;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    Solution solution;
    solution.rotate(a, k);
    for (auto x : a) {
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