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
int findMin(vector<int>& arr, int i, int n) {
    if(i == n-1) return i;
    int minIndex = findMin(arr, i+1, n);
    return (arr[i] < arr[minIndex]) ? i : minIndex;
}

void selectionSort(vector<int>& arr) {
    static int cur = 0;
    if(cur >= arr.size()) return;
    int minEle = findMin(arr, cur, arr.size());
    swap(arr[cur], arr[minEle]);
    cur+=1;
    selectionSort(arr);
}

signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    int n; cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    selectionSort(v);
    for(auto x:v){
        cout << x << " ";
    }
    return 0;
}