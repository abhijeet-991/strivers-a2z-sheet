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
void sortColors(vector<int>&a) {
    int left = 0, right = a.size()-1, itr = 0;
    while (itr < a.size() && itr <= right) {
        if (a[itr] == 2) {
            swap(a[itr], a[right]);
            right--;
        } else if (a[itr] == 1) {
            itr++;
        } else {
            swap(a[itr], a[left]);
            itr++;
            left++;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}