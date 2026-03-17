#include <bits/stdc++.h>
using namespace std;

class Solution {
    int maxi(vector<vector<int>> &arr, int n, int m, int col) {
        int maxelt = -1;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][col] > maxelt) {
                maxelt = arr[i][col];
                ind = i;
            }
        }
        return ind;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0; 
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxrow = maxi(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxrow][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxrow][mid + 1] : -1;

            if (mat[maxrow][mid] > left && mat[maxrow][mid] > right) return {maxrow, mid};

            else if (mat[maxrow][mid] < left) high = mid - 1;
            else low = mid + 1; 
        }

        return {-1, -1};
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> ans = s.findPeakGrid(mat);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}