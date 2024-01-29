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
int removeDuplicates(vector<int> &a, int n) {
    if(n == 1) return 1;
    int j = 0;
    for(int i=1;i<n;i++) {
        if(a[i] != a[j]) {
            a[j+1] = a[i];
            j++;
        }
    }
    return j+1;
}
void solve() {
    // int n; cin>>n;
    vector<int>v {1,2,2,2,3,4,5,6,6,7,9};
    // for(int i=0;i<n;i++) {
    //     int x; cin>>x;
    //     v.push_back(x);
    // }
    int length = removeDuplicates(v, v.size());
    for(int i=0;i<length;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    solve();
    return 0;
}