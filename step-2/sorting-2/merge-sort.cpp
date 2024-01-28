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
void merge(vector<int>&v, int leftArrayStartIndex, int leftArrayEndIndex, int rightArrayStartIndex, int rightArrayEndIndex) {
    vector<int>temp;
    int backedUpStartIndex = leftArrayStartIndex;
    int backedUpEndIndex = rightArrayEndIndex;
    while(leftArrayStartIndex <= leftArrayEndIndex && rightArrayStartIndex <= rightArrayEndIndex) {
        if(v[leftArrayStartIndex] <= v[rightArrayStartIndex]){
            temp.push_back(v[leftArrayStartIndex]);
            leftArrayStartIndex++;
        }
        else {
            temp.push_back(v[rightArrayStartIndex]);
            rightArrayStartIndex++;
        }
    }
    while(leftArrayStartIndex <= leftArrayEndIndex) {
        temp.push_back(v[leftArrayStartIndex]);
        leftArrayStartIndex++;
    }
    while(rightArrayStartIndex <= rightArrayEndIndex) {
        temp.push_back(v[rightArrayStartIndex]);
        rightArrayStartIndex++;
    }
    for(int m = backedUpStartIndex; m <= backedUpEndIndex; m++) {
        v[m] = temp [m - backedUpStartIndex]; // m may start from anywhere but temp array always has to start from 0
    }
}
void mergeSort(vector<int>&v, int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(v, start, mid);
    mergeSort(v, mid+1, end);
    merge(v, start, mid, mid+1, end);
}
signed main() {
    // bool prime[1000001];
    // invokePrime(prime);
    // tc { solve(); }
    // solve();
    vector<int>v;
    for(int i=0;i<100;i++){
        v.push_back(rand()%1000);
    }
    mergeSort(v,0,v.size()-1);
    for(auto x:v){
        cout << x << " ";
    }
    return 0;
}