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
    // int solve(vector<int>&nums) {
    //     int currentBest = 0, ans = INT_MIN;
    //     for (int i=0;i<nums.size();i++) {
    //         if (currentBest + nums[i] >= nums[i]) {
    //             currentBest += nums[i]; //if the original element is smaller than currentBest sum and current number combined, we should start the else condition such that max subarray will be retained
    //         } else {
    //             currentBest = nums[i];
    //         }
    //         ans = max(ans, currentBest);
    //     }
    //     return ans;
    // }

    int maxCrossingSum(vector<int> arr, int l, int m, int h) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i >= l; i--) {
            sum = sum + arr[i];
            if (sum > left_sum)
                left_sum = sum;
        }

        sum = 0;
        int right_sum = INT_MIN;
        for (int i = m + 1; i <= h; i++) {
            sum = sum + arr[i];
            if (sum > right_sum)
                right_sum = sum;
        }

        return max({ left_sum, right_sum, left_sum + right_sum });
    }

    int maxSubArraySum(vector<int> arr, int l, int h) {
        if (l == h)
            return arr[l];

        int m = (l + h) / 2;

        return max({ maxSubArraySum(arr, l, m),
                   maxSubArraySum(arr, m + 1, h),
                   maxCrossingSum(arr, l, m, h) });
    }
    int maxSubArray(vector<int>v) {
        return maxSubArraySum(v, 0, v.size() - 1);
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    // int n; cin >> n;
    vector<int>v = { 5,4,-1,7,8 };
    // for (auto& x : v) {
    //     cin >> x;
    // }
    cout << solution.maxSubArray(v);
    // tc { solution.solve(); }
    return 0;
}