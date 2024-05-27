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
    int lenOfLongSubarrBruteForce(int A[], int N, int K) {
        int cnt = 0, sum = 0, ans = 0, j = 0;
        for (int i = 0; i < N; i++) {
            cnt = 0, sum = 0, j = i;
            while (j < N) {
                sum += A[j];
                cnt++;
                if (sum == K) {
                    ans = max(cnt, ans);
                }
                j++;
            }
        }
        return ans;
    }
    // worst case will be O(n^2) in case of collision
    int lenOfLongSubarrBetterApproach(int A[], int N, int K) {
        long long sum = 0, ans = 0;
        unordered_map <long long, long long> mp;
        for (long long i = 0;i < N;i++) {
            sum += A[i];
            if (sum == K) {
                ans = max(ans, i + 1);
            }
            long long previousSum = sum - K;
            if (mp.find(previousSum) != mp.end()) {
                ans = max(ans, (i - mp[previousSum]));
            }
            if (mp.find(sum) == mp.end()) {
                mp.insert({ sum, i });
            }
        }
        return ans;
    }
    //sliding window only works for positives and 0's. consider test case [5,5,5-5,-5]
    int lenOfLongSubarrBestApproach(int A[], int N, int K) {
        long long sum = 0, ans = 0, left = 0, right = 0;
        while (right < N) {
            sum += A[right];
            while (sum > K) {
                sum -= A[left];
                left++;
            }
            if (sum == K) {
                ans = max(ans, right - left + 1);
            }
            right++;
        }
        return ans;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    Solution s;
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0;i < n;i++) cin >> a[i];
    cout << s.lenOfLongSubarrBruteForce(a, n, k) << "\n";
    return 0;
}