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
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx = 0, negIdx = 0;
        vector<int> posArray, negArray;
        posArray.reserve(nums.size() / 2);
        negArray.reserve(nums.size() / 2);
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] < 0) {
                negArray.push_back(nums[i]);
            }
            else posArray.push_back(nums[i]);
        }
        for (int i = 0;i < nums.size();i++) {
            if (i % 2 == 0) {
                nums[i] = posArray[posIdx];
                posIdx++;
            }
            else {
                nums[i] = negArray[negIdx];
                negIdx++;
            }
        }

        return nums;
    }

    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int posIdx = 0, negIdx = 1;
    //     vector<int>ans(n, 0);
    //     for (auto x : nums) {
    //         if (x > 0) {
    //             ans[posIdx] = x;
    //             posIdx += 2;
    //         }
    //         else {
    //             ans[negIdx] = x;
    //             negIdx += 2;
    //         }
    //     }
    //     return ans;
    // }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    vector<int> v = { 3,1,-2,-5,2,-4 };
    v = solution.rearrangeArray(v);
    for (auto x : v) {
        cout << x << " ";
    }
    // tc { solution.solve(); }
    return 0;
}