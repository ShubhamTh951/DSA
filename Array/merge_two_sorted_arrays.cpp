#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }

            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        for (int k = 0; k < m + n; k++) {
            nums1[k] = ans[k];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 0, 0, 0}; 
    int m = 3;                               
    vector<int> nums2 = {2, 4, 6};
    int n = 3;                            
    sol.merge(nums1, m, nums2, n);
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}