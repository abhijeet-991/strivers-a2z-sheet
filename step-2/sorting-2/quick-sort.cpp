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
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    int xkn2 = power(x, y / 2);
    int xkn = xkn2 * xkn2;
    if (y & 1)
        xkn *= x;
    return xkn;
}
void invokePrime(bool (&prime)[1000001])
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 1000001; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 1000001; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
int partition(vector<int> &v, int lo, int hi){
    int pivot = v[lo];
    int i = lo;
    int j = hi;
    while (i < j){
        while (v[i] <= pivot){
            i++;
        }
        while (v[j] > pivot){
            j--;
        }
        if (i < j){
            swap(v[i], v[j]);
        }
    }
    swap(v[lo], v[j]);
    return j;
}
void quickSort(vector<int> &v, int lo, int hi){
    if(lo >= hi) {
        return;
    }
    int partitionIndex = partition(v, lo, hi);
    quickSort(v, lo, partitionIndex-1);
    quickSort(v, partitionIndex+1, hi);
}
signed main()
{
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    // solve();
    vector<int> v{10,16,8,12,15,6,3,9,5};
    quickSort(v, 0, v.size()-1);
    for (auto x : v){
        cout << x << " ";
    }
    return 0;
}