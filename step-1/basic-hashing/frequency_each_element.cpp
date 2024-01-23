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
vector<int> countFrequency(int n, int x, vector<int> &nums) {
    for(int i=0;i<n;) {
        if(nums[i] <= 0 || nums[i] > n) i++;
        else {
            if(nums[nums[i]-1] > 0) {
                //we will check it as a sort of marking that if a number of is visited.
                int temp = nums[nums[i]-1]; // backup the value
                nums[nums[i]-1] = -1; //mark the current value as -1, which means it has come once atleast
                // Consider the case when i = 0 (the first iteration). The number at arr[0] is 1. 
                // According to the algorithm, we mark the occurrence of 1 by making nums[1-1] negative. 
                // So, nums[0] becomes -1.

                // In the next step, we swap nums[i] with nums[nums[i]-1]. But since nums[i] is 1 and i+1 is also 1, 
                // nums[nums[i]-1] is already -1. This means the number has been processed 
                // (its count has been marked as negative), and we don’t need to swap or process it again.

                // That’s where the line if(temp == i+1 && nums[temp-1] <= 0) continue; comes into play. 
                // It checks if the number (temp) is the same as the current index (i+1) 
                // and if the count of the number (nums[temp-1]) is less than or equal to 0 
                // (meaning it has been processed). If both conditions are true, 
                // it skips the rest of the loop for the current iteration and moves on to the next number in the array.
                if(temp == i+1 && nums[temp-1] <= 0) continue;
                nums[i]=temp; // set the backed up value to current element
            }
            else { // if it is already visited just decrement its count
                nums[nums[i]-1]--;
                nums[i]=0; // to skip this element next time
            }
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i] >= 0) {
            nums[i]=0;
            continue;
        }
        nums[i] = abs(nums[i]);
    }
    return nums;
}

void solve() {
    int n,x; cin>>n>>x;
    vector<int> ans(n, 0);
    for(auto &x:ans){
        cin>>x;
    }
    ans = countFrequency(n, x, ans);
    for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
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