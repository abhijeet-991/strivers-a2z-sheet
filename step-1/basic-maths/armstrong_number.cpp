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
int countDigits(int n){
	return floor(log10(n)+1);
}
bool checkArmstrong(int n){
	int originalN = n;
	int ans=0;
	int cntOfDigits = countDigits(n);
	while(n){
		int ones = n%10;
		ans = ans + pow(ones,cntOfDigits);
		n/=10;
	}
	return ans == originalN;
}
void solve() {
    cout << checkArmstrong(1634) << endl; //returns 1
    cout << checkArmstrong(321) << endl; //returns 0
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    solve();
    return 0;
}