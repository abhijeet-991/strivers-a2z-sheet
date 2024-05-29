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
    // void markRow(int row, int col, vector<vector<int>>& matrix) {
    //     for (int col = 0; col < matrix[0].size(); col++) {
    //         if (matrix[row][col] != 0) {
    //             matrix[row][col] = INT_MAX;
    //         }
    //     }
    // }
    // void markColumn(int row, int col, vector<vector<int>>& matrix) {
    //     for (int row = 0; row < matrix.size(); row++) {
    //         if (matrix[row][col] != 0) {
    //             matrix[row][col] = INT_MAX;
    //         }
    //     }
    // }
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int zeroRow = 0;
    //     int zeroColomn = 0;

    //     for (int i = 0;i < matrix.size();i++) {
    //         for (int j = 0; j < matrix[i].size();j++) {
    //             if (matrix[i][j] == 0) {
    //                 markRow(i, j, matrix);
    //                 markColumn(i, j, matrix);
    //             }
    //         }
    //     }

    //     for (int i = 0;i < matrix.size();i++) {
    //         for (int j = 0;j < matrix[i].size();j++) {
    //             if (matrix[i][j] == INT_MAX) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<bool>rows(matrix.size(), false); //false indicates no zero is found in the current row initially
    //     vector<bool>cols(matrix[0].size(), false);

    //     for (int i = 0;i < matrix.size();i++) {
    //         for (int j = 0; j < matrix[i].size();j++) {
    //             if (matrix[i][j] == 0) {
    //                 rows[i] = true;
    //                 cols[j] = true;
    //             }
    //         }
    //     }

    //     //mark row as 0
    //     for (int i = 0; i < rows.size(); i++) {
    //         if (rows[i]) {
    //             for (int col = 0; col < matrix[0].size(); col++) {
    //                 matrix[i][col] = 0;
    //             }
    //         }
    //     }
    //     //mark col as 0
    //     for (int i = 0; i < cols.size(); i++) {
    //         if (cols[i]) {
    //             for (int row = 0; row < matrix.size(); row++) {
    //                 matrix[row][i] = 0;
    //             }
    //         }
    //     }
    // }
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // bool prime[1000001];
    // invokePrime(prime);
    Solution solution;
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
    solution.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // tc { solution.solve(); }
    return 0;
}