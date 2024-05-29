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
    // int longestConsecutive(vector<int>& nums) {
    //     if (nums.empty()) return 0;
    //     set<int> s(nums.begin(), nums.end());
    //     int cnt = 1, ans = 1;
    //     auto prev = s.begin();
    //     for (auto it = ++s.begin(); it != s.end(); it++) {
    //         if (*it - *prev == 1) {
    //             cnt++;
    //         }
    //         else {
    //             cnt = 1;
    //         }
    //         ans = max(cnt, ans);
    //         prev = it;
    //     }
    //     return ans;
    // }

    // int longestConsecutive(vector<int>& nums) { 
    //     if (nums.size() == 0) return 0;
    //     int n = nums.size();
    //     int cnt=0, ans = 1;
    //     sort(nums.begin(), nums.end());
    //     int lastSmaller = INT_MAX-1;
    //     for (int i = 0;i < nums.size(); i++) {
    //         //if last smaller element is same as nums[i] that means the element is repeated, leave it.
    //         if (lastSmaller == nums[i]) continue;
    //         //check if nums[i] can be part of the sequence
    //         if (lastSmaller + 1 == nums[i]) {
    //             cnt++;
    //         } else {
    //             cnt = 1;
    //         }
    //         lastSmaller = nums[i];
    //         ans = max(ans, cnt);
    //     }
    //     return ans;
    // }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : s) {
            if (!s.count(num - 1)) {  //only start counting if the previous element in the series is present
                int currentNum = num;
                int currentStreak = 1;

                while (s.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    vector<int>v = { 100,4,200,1,3,2 };
    cout << solution.longestConsecutive(v);
    // tc { solution.solve(); }
    return 0;
}