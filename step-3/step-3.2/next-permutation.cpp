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
    void nextPermutation(vector<int>& nums) {
        int elementIndexThatCanBeIncreased = -1, elementThatCanBeIncreased = 0;
        int findNextGreaterElementThenElementThatCanBeIncreased = INT_MAX;
        int nextGreaterElementIndex = -1;
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                elementThatCanBeIncreased = nums[i - 1];
                elementIndexThatCanBeIncreased = i - 1;
                break;
            }
        }

        if (elementIndexThatCanBeIncreased == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i >= elementIndexThatCanBeIncreased + 1;i--) {
            if (nums[i] == 0)
                continue;
            if (nums[i] > elementThatCanBeIncreased) {
                if (nums[i] < findNextGreaterElementThenElementThatCanBeIncreased) {
                    findNextGreaterElementThenElementThatCanBeIncreased = nums[i];
                    nextGreaterElementIndex = i;
                }
            }
        }
        swap(nums[elementIndexThatCanBeIncreased], nums[nextGreaterElementIndex]);

        reverse(nums.begin() + elementIndexThatCanBeIncreased + 1, nums.end());
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    vector<int>v = { 2,1,5,4,3,0,0 };
    solution.nextPermutation(v);
    cout << endl;
    for (auto x : v) {
        cout << x << " ";
    }
    // tc { solution.solve(); }
    return 0;
}