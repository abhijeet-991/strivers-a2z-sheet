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
vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v;
    int k = 0;
    for (auto x : nums) {
        v.push_back(make_pair(x, k));
        k++;
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        sum = v[i].first + v[j].first;
        if (sum == target) {
            return { v[i].second,v[j].second };
        }
        else if (sum > target) {
            j--;
        }
        else i++;
    }
    return { -1,-1 }; //doesn't matter since answer always exists
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    int n; cin >> n;
    vector<int>v;
    for (int i = 0;i < n;i++) {
        int x;cin >> x;
        v.push_back(x);
    }
    int target; cin >> target;
    vector<int> ans = twoSum(v, target);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}