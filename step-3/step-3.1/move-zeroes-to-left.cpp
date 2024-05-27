#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int zeroIndex = findFirstIndexWith0(a);
        int i = 0;
        while (i < a.size()) {
            if (a[i] != 0 && i > zeroIndex) { //second condition is there because we dont need to worry about already sorted elements, so we begin after the first 0 found.
                swap(a[i], a[zeroIndex]);
                zeroIndex++;
            }
            i++;
        }
    }
private:
    int findFirstIndexWith0(vector<int>a) {
        for (int i = 0;i < a.size();i++) {
            if (a[i] == 0) return i;
        }
        return a.size() - 1;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int n;
    // cin >> n;
    vector<int> a{ 0,0,1 };
    // for (int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     a.push_back(x);
    // }
    Solution solution;
    solution.moveZeroes(a);
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
