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
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = 0, profit = 0, ans = 0;
        for (int i=1;i<prices.size();i++) {
            sell = prices[i];
            profit = sell - buy;
            if (sell < buy) {
                buy = sell;
            }
            if (profit > 0 && profit > ans) {
                ans = profit;
            }
        }
        return ans;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    vector<int> v= {15,2,51,5,91};
    solution.maxProfit(v);
    // tc { solution.solve(); }
    return 0;
}