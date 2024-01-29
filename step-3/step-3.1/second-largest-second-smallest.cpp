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
int largestElement(vector<int> &arr, int n) {
    int ans = INT_MIN;
    for(int i=0;i<arr.size();i++) {
        ans = max(ans, arr[i]);
    }
    return ans;
}
int smallestElement(vector<int> &v, int n) {
    int ans = INT_MAX;
    for(int i=0;i<v.size();i++) {
        ans = min(ans, v[i]);
    }
    return ans;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largestElem = largestElement(a, n);
    int smallestElem = smallestElement(a, n);
    int secondLargest = INT_MIN;
    int secondSmallest = INT_MAX;
    for(auto x:a) {
        if(x < largestElem) {
            secondLargest = max(secondLargest, x);
        }
    }
    for(auto x:a){
        if(x > smallestElem) {
            secondSmallest = min(secondSmallest, x);
        }
    }
    return {secondLargest, secondSmallest};
}
void solve() {
    int n; cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    v = getSecondOrderElements(n, v);
    cout << v[0] << " " << v[1] << "\n";
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    solve();
    return 0;
}